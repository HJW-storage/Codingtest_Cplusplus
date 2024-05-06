// https://www.acmicpc.net/problem/1912
// 완탐 불가. dp 이용.

#include <iostream>
#include <algorithm>

using namespace std;
#define max_n 100'004

int n = 0, arr[max_n] = { 0, }, dp[max_n] = { 0, };

int solve_dp() {
	// 초기화
	fill(&dp[0], &dp[0] + max_n, -1004); // 엄청 작은 수로 초기화.
	dp[1] = arr[1];

	// 메모리제이션, 로직구현
	// 쌓아오면서 최대합 구하기.
	for (int i = 2; i <= n; i++) {
		// 음수(1) + 음수(2) 이면 더 작은 값이 되므로 더하지 않는다. 음수(2)만 대입.
		if (dp[i - 1] < 0 && arr[i] < 0) {
			dp[i] = arr[i];
		}
		// 음수(1) + 양수(2) 이면 작은 값이 되므로 더하지 않는다. 양수(2)만 대입.
		else if (dp[i - 1] < 0 && arr[i] >= 0) {
			dp[i] = arr[i];
		}
		// 양수(1) + 음수(2) 이면 더한다 => 이후, 연속된 수의 합을 계산하는 것이므로, 다음턴의 양수가 있는 경우 더해주는 징검다리 역할
		else if (dp[i - 1] >= 0 && arr[i] < 0) {
			dp[i] = dp[i-1] + arr[i];
		}
		// 양수(1) + 양수(2) 이면 더한다
		else if (dp[i - 1] >= 0 && arr[i] >= 0) {
			dp[i] = dp[i - 1] + arr[i];
		}
	}

	// 최대합 찾기.
	int max_res = -1004;
	for (int i = 1; i <= n; i++) {
		max_res = max(max_res, dp[i]);
	}

	return max_res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << solve_dp() << "\n";
	return 0;
}