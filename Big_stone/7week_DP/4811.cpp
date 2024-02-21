// https://www.acmicpc.net/problem/4811

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n = 0;
ll dp[34][34] = { 0, };

ll solve_dp(int w, int h) {
	// 종료 조건
	if (w == 0) return 1;
	if (h < 0) return 0;

	// 메모리제이션, 로직구현
	if (dp[w][h]) return dp[w][h];
	else dp[w][h] = solve_dp(w - 1, h + 1) + solve_dp(w, h - 1);

	return dp[w][h];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	// 초기화 
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << solve_dp(n, 0) << "\n";
	}
	return 0;
}