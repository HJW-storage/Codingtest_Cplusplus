// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int v_tri[504][504] = { 0, }, dp[504][504] = { 0, };
int n = 0;

void solve_dp() {
	// 기저사례
	dp[0][0] = v_tri[0][0];

	// 메모리제이션, 로직 구현
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + v_tri[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + v_tri[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v_tri[i][j];
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v_tri[i][j];
		}
	}

	solve_dp();
	int res = 0;
	// dp[n-1] 행에서 최댓값을 구한다
	for (int i = 0; i < n; i++) {
		res = max(res, dp[n - 1][i]);
	}
	cout << res << "\n";
	return 0;
}