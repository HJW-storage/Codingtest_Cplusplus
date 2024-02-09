// https://www.acmicpc.net/problem/2636
#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>> &one_vec) {
	visited[row][col] = 1; // 방문처리
	if (grid[row][col] == 1) {
		one_vec.push_back({ row, col });
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (visited[next_row][next_col] == 0) {
				solve_dfs(next_row, next_col, grid, visited, one_vec);
			}
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	vector<pair<int, int>> one_vec;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int hour = 0;
	int left_cheese = 0;
	while (true) {
		fill(visited.begin(), visited.end(), vector<int>(m, 0));	// 0으로 초기화
		one_vec.clear();

		solve_dfs(0, 0, grid, visited, one_vec);
		left_cheese = one_vec.size();
		
		// 1시간 지나면서 치즈 없애기

		for (pair<int, int> it : one_vec) {
			grid[it.first][it.second] = 0;
		}

		hour++;

		// 남은 치즈가 있는지 검사
		bool exist_cheese = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] != 0) { exist_cheese = true; }
			}
		}

		if (exist_cheese == false) break;
	}

	cout << hour << "\n";
	cout << left_cheese << "\n";
	return 0;
}