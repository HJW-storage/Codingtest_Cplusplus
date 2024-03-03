// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 1'000'004
int A[max_n] = { 0, }, n = 0, dp[max_n] = { 0, }, res_max = 0;
// 시간복잡도 O(N*N)  /  N <= 1,000
int solve_dp() {
	// 기저사례
	dp[1] = 1;
	res_max = 1;

	// 메모리제이션, 로직 구현
	for (int i = 2; i <= n; i++) {
		int max_p = 0;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				max_p = max(max_p, dp[j]);
			}
		}
		dp[i] = max_p + 1;
		res_max = max(res_max, dp[i]);
	}
	return res_max;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	cout << solve_dp() << "\n";
	return 0;
}