// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m = 0, n = 0, k = 0;
int cnt = 1;	// cnt 전역변수로 선언해서 dfs에서 넓이 카운트시 사용.

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
	visited[row][col] = true;	// 방문처리
	const int dr[4] = {-1, 0, 1, 0};
	const int dc[4] = {0, 1, 0, -1};

	int next_row, next_col;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n) {
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == false) {
				cnt++;
				solve_dfs(next_row, next_col, grid, visited);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	vector<vector<int>> grid(m, vector<int>(n, 0));
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int i = 0; i < k; i++) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		int row_len = y2 - y1;
		int col_len = x2 - x1;

		int start_row = m - y1 - row_len;
		int row_range = start_row + row_len;

		int start_col = x1;
		int col_range = start_col + col_len;

		//cout << start_row << "\t" << start_col << "\n";
		// 직사각형 넓이에 해당하는 grid 인덱스에 맞게 1로 채우기
		for (int i = start_row; i < row_range; i++) {
			for (int j = start_col; j < col_range; j++) {
				grid[i][j] = 1;
			}
		}

		/*for (int i = 0; i < grid.size(); i++) {
			for (auto it : grid[i]) {
				cout << it << " ";
			}
			cout << "\n";
		}*/
	}
	vector<int> res;

	int result = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0 && visited[i][j] == false) {
				cnt = 1; // (cnt는 전역변수로 선언했다.) dfs 시작을 했다면 최소 넓이는 1이기에 1로 초기화 해준다. 
				// 또한 문제 조건에서 "입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다."이기에 1로 한다. 
				
				solve_dfs(i, j, grid, visited);
				result++;
				res.push_back(cnt);
			}
		}
	}

	cout << result << "\n";
	// 문제 조건을 통해 최소 1개 이상은 res 벡터에 값이 들어오게 된다.
	sort(res.begin(), res.end());
	for (int it : res) cout << it << " ";

	return 0;
}