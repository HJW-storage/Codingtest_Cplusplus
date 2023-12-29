// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int solve_bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
	visited[row][col] = 1;	// 방문처리
	queue<pair<int, int>> q;

	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };

	q.push({ row, col });
	int cur_row, cur_col, next_row, next_col;

	while (q.size()) {
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (grid[next_row][next_col] == 1 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
					q.push({ next_row, next_col });
				}
			}
		}
	}

	return visited[n - 1][m - 1];
}

int main() {
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));

	// 빈칸 없이 입력받는 경우.
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			grid[i][j] = num[j] - '0';
		}
	}

	int result = solve_bfs(0, 0, grid, visited);
	cout << result << "\n";


	return 0;
}