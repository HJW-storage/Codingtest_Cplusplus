// https://www.acmicpc.net/problem/2293
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, k = 0, dp[10004] = { 0, }, coins[10004] = {0,};

// 순서가 달라도 같은 것으로 본다. -> 동전 k1 먼저 채우고, k2 채우고, k3 마저 채우는 식으로 dp 쌓아간다.
int solve_dp() {
	// 기저사례
	dp[0] = 1; // 이후, 메모리제이션 편하게 하기위해 dp[0] = 1로 해둔다.
	
	// 메모리제이션, 로직구현
	for (int t = 1; t <= n; t++) {
		for (int j = coins[t]; j <= k; j++) {
			dp[j] = dp[j - coins[t]] + dp[j];
		}
	}
	return dp[k];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	cout << solve_dp() << "\n";
	return 0;
}