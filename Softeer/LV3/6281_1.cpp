// https://softeer.ai/practice/6281

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
int n = 0, m = 0, grid[104][104] = { 0, }, grid_cnt[104][104] = {0,};
bool visited[104][104] = { false, };
int ice_cnt = 0, res = 0;

void wrap(int row, int col) {
	// 초기화
	fill(&visited[0][0], &visited[0][0] + 104 * 104, false);
	fill(&grid_cnt[0][0], &grid_cnt[0][0] + 104 * 104, 0);

	visited[row][col] = true; // 방문처리
	queue<pair<int, int>> q;
	q.push({ row, col });
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (q.size()) {
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (visited[next_row][next_col]) continue;
			
			if (grid[next_row][next_col] == 1) {
				grid_cnt[next_row][next_col]++;
			}
			else {
				visited[next_row][next_col] = true; // 방문처리
				q.push({ next_row, next_col });
			}
		}
	}
 	return;
}
void melt_ice() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid_cnt[i][j] >= 2) {
				grid[i][j] = 0; // 얼음 녹이기
				ice_cnt--;
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);  cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) ice_cnt++;
		}
	}

	while (ice_cnt > 0) {
		wrap(0, 0); // wrapping 은 0,0 에서 시작
		melt_ice();	// 얼음 녹이기
		res++;
	}
	cout << res << "\n";
	return 0;
}