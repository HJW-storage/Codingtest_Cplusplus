// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 1'500'004
int n = 0, T[max_n] = { 0, }, P[max_n] = { 0, }, dp[max_n] = { 0, };

// dp 배열에는 최대 값을 저장해 나가자.
int solve_dp() {
	// 기저사례
	if (T[n] == 1) dp[n] = P[n];
	else dp[n] = 0;

	// 메모리제이션, 로직 구현
	// dp 배열 뒤에서 부터 채우는게 더 쉽게 구현이 된다.
	for (int j = n - 1; j > 0; j--) {
		// n+1 보다 크게 한 것은 -> 다음 아래 예시에서 6번일을 하면 7번일을 안하는 경우다.
		// 1 2 3 4 5 6 7
		// - - - - - 2 1
		// - - - - - 9 5
		// n+1 까지만 허용된다. 
		// dp[n+1 = 8] 은 0이기에 -> dp[6] = dp[8] (0) + P[6] 과 dp[7]중 최대 값이 저장되게된다.
		if (T[j] + j > n + 1) {
			dp[j] = dp[j + 1]; // 해당 날짜에 일 못하므로 이전거 그대로 가져오자.
		}
		else {
			dp[j] = max(dp[T[j] + j] + P[j], dp[j + 1]);
		}
	}
	return dp[1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	cout << solve_dp() << "\n";
	return 0;
}