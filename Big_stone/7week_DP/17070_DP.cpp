// https://www.acmicpc.net/problem/17070

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, grid[20][20] = { 0, }, dp[20][20][3] = {0,};

// 0 : 가로, 2 : 세로   /    1 : 대각선
bool check(int row, int col, int dir) {
	if (dir == 0 || dir == 2) {
		// 벽이 아니라면
		if (grid[row][col] == 0) return true;
	}
	else if (dir == 1) {
		if (grid[row][col] == 0 && grid[row - 1][col] == 0 && grid[row][col - 1] == 0) return true;
	}
	return false;
}

// 기둥의 끝점 좌표만 고려해도 된다. 
int solve_dp() {
	// 기저사례
	dp[1][2][0] = 1;

	// 메모리제이션, 로직구현
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 가로 위치(기존 dir : 0)에서 움직이는 경우(2가지)
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];
		
			// 세로 위치(기존 dir : 2)에서 움직이는 경우(2가지)
			if (check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

			// 대각선 위치(기존 dir : 1)에서 움직이는 경우(3가지)
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	int res = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solve_dp() << "\n";
	return 0;
}