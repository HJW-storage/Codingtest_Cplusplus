// https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, dp[10004] = { 0, }, arr[10004] = { 0, };
int solve_dp() {
	// 기저사례
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	// 메모리제이션, 로직구현
	for (int i = 3; i <= n; i++) {
		dp[i] = max({ (dp[i - 2] + arr[i]), (dp[i - 3] + arr[i - 1] + arr[i]), (dp[i - 1]) });
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << solve_dp() << "\n";
	return 0;
}