// https://www.acmicpc.net/problem/4811

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n = 0;
ll dp[34][34] = { 0, };

ll solve_dp_TopDown(int w, int h) {
	// 종료 조건
	if (w == 0) return 1;
	if (h < 0) return 0;

	// 메모리제이션, 로직구현
	if (dp[w][h]) return dp[w][h];
	else dp[w][h] = solve_dp_TopDown(w - 1, h + 1) + solve_dp_TopDown(w, h - 1);

	return dp[w][h];
}

ll bottom_up() {
	// 기저사례
	for (int i = 0; i <= 30; i++) {
		dp[0][i] = 1;
	}

	// 메모리제이션, 로직구현
	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
		}
	}
	return dp[n][0];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	// 초기화 
	while (1) {
		cin >> n;
		if (n == 0) break;
		// top-down 방식
		 cout << solve_dp_TopDown(n, 0) << "\n";
		
		// bottom_up 방식
		/*bottom_up();
		cout << dp[n][0] << "\n";*/
	}
	return 0;
}