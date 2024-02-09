// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n, k, test_case;

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
	visited[row][col] = 1;	// 방문처리
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	
	int next_row, next_col;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == 1 && visited[next_row][next_col] == 0) {
				solve_dfs(next_row, next_col, grid, visited);
			}
		}
	}
	return;
}
int main() {
	cin >> test_case;
	
	for (int t = 0; t < test_case; t++) {
		cin >> m >> n >> k;
		int result = 0;
		int x = 0, y = 0;
		vector<vector<int>> grid(n, vector<int>(m, 0));
		vector<vector<int>> visited(n, vector<int>(m, 0));

		for (int i = 0; i < k; i++) {
			cin >> x >> y; // x : 열, y : 행
			grid[y][x] = 1;	// 배추 심어주기.
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(grid[i][j] == 1 && visited[i][j] == 0){ // 방문하지 않은 곳에 한해. 해당 코드를 넣는게 시간 좀더 줄인다.
					solve_dfs(i, j, grid, visited);
					result++;
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}