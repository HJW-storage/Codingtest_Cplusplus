#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n = 0, grid[20][20] = { 0, }, dp[20][20][3] = { 0, };

int solve_dp() {
	// 기저사례
	dp[1][2][0] = 1; // 처음 위치 가로방향. 

	// 메모리제이션, 로직구현
	// 
	// 1행 가로방향 밀기 
	for (int i = 3; i <= n; i++) {
		if (grid[1][i] == 1) break;
		dp[1][i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (grid[i][j] != 1) {
				// 가로 방향으로 (밀어지는)끝날 수 있는 방법 = 이전 dp의 가로 방향으로 끝난 방법 수 + 대각선 방향으로 끝난 방법 수
				dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][1]; 

				// 세로 방향으로 (밀어지는)끝날 수 있는 방법 = 이전 dp의 세로 방향으로 끝난 방법 수 + 대각선 방향으로 끝난 방법 수
				dp[i][j][2] += dp[i-1][j][2] + dp[i-1][j][1]; 
				
				// 대각섭 방향은 추가적인 검사 필요.
				if (grid[i - 1][j] != 1 && grid[i][j - 1] != 1) {
					// 대각선 방향으로 (밀어지는)끝날 수 있는 방법 = 이전 dp 가로 + 세로 + 대각선 방향으로 끝난 방법 수
					dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1];
				}
			}
		}
	}

	// 최종 결과 = 가로 + 대각선 + 세로 방향으로 밀어지는 끝날 수 있는 방법들의 합.
	int res = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solve_dp() << "\n";
	return 0;
}