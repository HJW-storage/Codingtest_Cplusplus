// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void solve_dfs(int row, int col, int water_height, vector<vector<int>>& grid, vector<vector<int>>& visited) {
	visited[row][col] = 1;	// 방문처리
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };

	int next_row, next_col;

	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
			if (grid[next_row][next_col] > water_height && visited[next_row][next_col] == 0) {
				solve_dfs(next_row, next_col, water_height, grid, visited);
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	vector<int> safety_land(n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	// 어느곳도 물에 잠기지 않을 때는 안전한 영역은 한덩어리 1이 되므로 1이 출력되야한다. 
	// 비가 오지 않은 날도 있으므로 0부터 시작해준다. 
	for(int water_height = 0; water_height <= 100; water_height++){
		int result = 0;
		vector<vector<int>> visited(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] > water_height && visited[i][j] == 0) {
					solve_dfs(i, j, water_height, grid, visited);
					result++;
				}
			}
		}
		safety_land.push_back(result);
	}

	sort(safety_land.begin(), safety_land.end());
	cout << *(safety_land.end() - 1) << "\n";
	return 0;
}