// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> res;	// 안정영역 개수 담을 벡터

void solve_bfs(int row, int col, vector<vector<int>>& tmp_grid, vector<vector<int>>& visited) {
	visited[row][col] = 1;	// 방문처리
	queue<pair<int, int>> q;
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = {1, 0, -1, 0};
	q.push({ row, col });

	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if(next_row >= 0 && next_row < n && next_col >= 0 && next_col < m){
				// tmp_grid[next_row][next_col] == 0 이 아니라 != 1로 한 이유는
				// 1(벽)이 아닐때만 피하고, 0(빈 공간)과 2(바이러스)를 2일 때에는 방문하여 방문처리를 한다.
				// 방문처리를 bfs 내부에서 해주면 향후 main 에서 for문 돌며 다시 bfs하는 것을 줄일 수 있다.   
				if (tmp_grid[next_row][next_col] != 1 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = 1;	// 방문처리
					tmp_grid[next_row][next_col] = 2;
					q.push({ next_row, next_col });
				}
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<pair<int, int>> zero_rc;

	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int in_tmp = 0;
			cin >> in_tmp;
			grid[i][j] = in_tmp;
			if (in_tmp == 0) zero_rc.push_back({ i, j });
		}
	}

	// 3개 뽑는 조합 완성
	for (int i = 0; i < zero_rc.size(); i++) {
		for (int j = i + 1; j < zero_rc.size(); j++) {
			for (int k = j + 1; k < zero_rc.size(); k++) {
				vector<vector<int>> tmp_grid(n, vector<int>(m, 0));
				vector<vector<int>> visited(n, vector<int>(m, 0));
				tmp_grid = grid;	// 깊은 복사

				int row1 = zero_rc[i].first; int col1 = zero_rc[i].second;
				int row2 = zero_rc[j].first; int col2 = zero_rc[j].second;
				int row3 = zero_rc[k].first; int col3 = zero_rc[k].second;
				// 조건 검사로 입력 받은 grid에 이미 0이 아니면 해당 횟수는 건너뛴다. 모두 0일때만 실행.
				// 1로 바꾼다.
				if (tmp_grid[row1][col1] == 0 && tmp_grid[row2][col2] == 0 && tmp_grid[row3][col3] == 0) {
					tmp_grid[row1][col1] = 1;
					tmp_grid[row2][col2] = 1;
					tmp_grid[row3][col3] = 1;

					// dfs 혹은 bfs를 이용하여 바이러스 전염시키고 0개수 세기.
					for (int r = 0; r < n; r++) {
						for (int c = 0; c < m; c++) {
							if (tmp_grid[r][c] == 2 && visited[r][c] == 0) {
								solve_bfs(r, c, tmp_grid, visited);
							}
						}
					}
					// tmp_grid에서 0개수 세서 rec 벡터에 넣기.
					int cnt = 0;
					for (int r = 0; r < n; r++) {
						for (int c = 0; c < m; c++) {
							if (tmp_grid[r][c] == 0) {
								cnt++;
							}
						}
					}
					res.push_back(cnt);
				}

			}
		}
	}
	// rec 벡터 오름차순 정렬 후, 마지막 원소 값 출력하기.
	sort(res.begin(), res.end());
	cout << *(res.end() - 1) << "\n";
	return 0;
}