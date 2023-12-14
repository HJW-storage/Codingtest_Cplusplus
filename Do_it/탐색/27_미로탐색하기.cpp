#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// 2차원 배열 입력 받기
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			grid[i][j] = a[j] - '0';
		}
	}

	int result = bfs(0, 0, grid, visited, n, m);

	cout << result << "\n";
}

int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m) {

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(r, c, 1));
	visited[r][c] = true;

	int dr[4] = { 0, 1, 0, -1 };
	int dc[4] = { 1, 0, -1, 0 };


	int next_r, next_c, cur_r, cur_c, distance;
	while (!q.empty()) {
		cur_r = get<0>(q.front());
		cur_c = get<1>(q.front());
		distance = get<2>(q.front());
		if (cur_r == n - 1 && cur_c == m - 1) {
			return distance;
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_r = cur_r + dr[i];
			next_c = cur_c + dc[i];
			if (next_r < n && next_r >= 0 && next_c < m && next_c >= 0) {
				if (grid[next_r][next_c] == 1) {
					if (!visited[next_r][next_c]) {
						visited[next_r][next_c] = true;		// 방문처리
						q.push(make_tuple(next_r, next_c, distance + 1));
					}
				}
			}
		}
	}
}