// https://www.acmicpc.net/problem/2636
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int n = 0, m = 0, cheese_cnt = 0, res_hour = 0, check = 3;

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
	visited[row][col] = true; // 방문처리

	// 로직 설계
	grid[row][col] = check;	// 치즈에 구멍과 구별하기 위해 99로 저장. 
	int next_row = 0, next_col = 0;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == false) {
				solve_dfs(next_row, next_col, grid, visited);
			}
		}
	}
}

void delete_cheese(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>> &zero_idx) {
	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == 1 && visited[next_row][next_col] == false) {
				grid[next_row][next_col] = check;
				visited[next_row][next_col] = true;	// 방문처리
				cheese_cnt--;

				// 치즈에 구멍있는지 검사해봤다.
				for (int i = 0; i < 4; i++) {
					int nnext_row = next_row + dr[i];
					int nnext_col = next_col + dc[i];
					if (nnext_row >= 0 && nnext_row < n && nnext_col >= 0 && nnext_col < m) {
						if (grid[nnext_row][nnext_col] == 0 && visited[nnext_row][nnext_col] == false) {
							zero_idx.push_back({ nnext_row, nnext_col });
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) cheese_cnt++;
		}
	}

	// int prev_cheese_cnt = 0; <- 맨 처음 0으로 선언했는데, 
	// 이렇게 되면 내 코드상 1시간 만에 녹아 없어지는 치즈의 경우는 맨처음 치즈 수가 출력되어야하는데 0이 출력되니 오류이다.
	int prev_cheese_cnt = cheese_cnt;

	// 문제 조건에서 가장 자리에는 치즈가 없다고 했기에 dfs를 0,0에서 시작하고 가자.
	solve_dfs(0, 0, grid, visited);

	while (cheese_cnt) {
		vector<pair<int, int>> zero_idx;	// 매번 초기화. 치즈 구멍이 뚫렸을 때, 해당 부분 공기로 채우기 위해 필요한 벡터.
		int prev_check = check;
		check++;

		// 치즈 지워보기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == prev_check) {
					delete_cheese(i, j, grid, visited, zero_idx);
				}
			}
		}
		res_hour++;
		if (cheese_cnt == 0) break;
		prev_cheese_cnt = cheese_cnt;

		// 치즈 구멍에 빈틈이 생겨서 공기가 등러갔다면 dfs 돌려서 공기가 접촉했다는 정보 남기기.
		if (zero_idx.size() != 0) {
			for (pair<int, int> it : zero_idx) solve_dfs(it.first, it.second, grid, visited);
		}
	}

	cout << res_hour << "\n";
	cout << prev_cheese_cnt << "\n";
	return 0;
}