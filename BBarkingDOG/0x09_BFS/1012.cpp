// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define max_n 54
#define Cabbiage 1

int res = 0, grid[max_n][max_n] = { 0, }, visited[max_n][max_n] = {0,}, Test_Case = 0, n = 0, m = 0, k = 0;
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = { 1, -1, 0, 0 };

int solve_bfs(int row, int col) {

	queue<pair<int, int>> q;
	q.push({ row, col });
	visited[row][col] = 1; // 초기 방문처리
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	
	while (q.size()) {
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (visited[next_row][next_col] > 0) continue; // 방문한 곳이면
			if (grid[next_row][next_col] == 1) {
				visited[next_row][next_col] = 1; // 방문처리
				q.push({ next_row, next_col });
			}
		}
	}
	
	return 1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> Test_Case;
	while (Test_Case--) {
		// 초기화 
		fill(&grid[0][0], &grid[0][0] + max_n * max_n, 0);
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
		res = 0;

		cin >> m >> n >> k;	// m : 열, n : 행

		int _row = 0, _col = 0;
		for (int i = 0; i < k; i++) {
			cin >> _col >> _row;
			grid[_row][_col] = Cabbiage; // 배추가 심어져있는 곳.
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && grid[i][j] == 1) {
					res += solve_bfs(i, j);
				}
			}
		}
		cout << res << "\n";
	}

	return 0;
}