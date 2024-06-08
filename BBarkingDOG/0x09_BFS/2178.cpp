// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define max_n 104

int n = 0, m = 0, grid[max_n][max_n] = { 0, }, visited[max_n][max_n] = { 0, };
const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

int solve_bfs(int row, int col) {
	int res = 1;

	visited[row][col] = 1; // 방문처리
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (q.size()) {
		tie(cur_row, cur_col) = q.front();
		q.pop();
		if (cur_row == n - 1 && cur_col == m - 1) break;

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (visited[next_row][next_col] == 0 && grid[next_row][next_col] == 1) {
				visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
				q.push({ next_row, next_col });
			}
		}
	}
 	return visited[n-1][m-1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	string _tmp = "";
	for (int i = 0; i < n; i++) {
		cin >> _tmp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = _tmp[j] - '0';
		}
	}

	cout << solve_bfs(0, 0) << "\n";
	return 0;
}