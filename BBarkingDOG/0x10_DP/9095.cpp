// https://www.acmicpc.net/problem/9095

// n <= 10 양수. -> 완전 탐색, DP 풀이 모두 가능.
#include <iostream>
#include <algorithm>

using namespace std;
int n = 0, t = 0;
int dp[14];

// 완전탐색
int res = 0; 
void Full_Search(int idx, int sum) {
	// 종료 조건
	if (idx > 10) return;
	if (sum == n) {
		res++;
		return;
	}

	// 탐색 (1, 2, 3으로 각각 더하는 경우)
	Full_Search(idx + 1, sum + 1);
	Full_Search(idx + 2, sum + 2);
	Full_Search(idx + 3, sum + 3);

	return;
}

// DP() 풀이
void solve_DP() {
	// 기저 사례
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// 메모리제이션 (로직)
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;
	//solve_DP();
	while (t--) {
		cin >> n; // 초기화. 
		//cout << dp[n] << "\n";

		res = 0; // 초기화
		Full_Search(0, 0); // 1부터 시작
		cout << res << "\n";
	}

	return 0;
}