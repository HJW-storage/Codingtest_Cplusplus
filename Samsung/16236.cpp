// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n = 0, grid[24][24] = { 0, }, visited[24][24] = { 0, }, res = 0, shark_size = 2;
const int dr[4] = { -1, 0, 0, 1 };
const int dc[4] = { 0, -1, 1, 0 };
pair<int, int> baby_shark;
vector<tuple<int, int, int>> shark_v; // 아기상어가 잡아 먹을 수 있는 물고기 정보 저장 벡터.

void Qclear(queue<pair<int, int>> &vq) {
	queue<pair<int, int>> emptyq;
	swap(vq, emptyq);
	return;
}
void solve_bfs(int row, int col) {
	// 아기상어가 물고기를 잡아 먹었으면 visited 초기화. 
	// 같은 크기는 그냥 통과. 큰 크기는 통과 x

	visited[row][col] = 0; // 초기 방문처리
	queue<tuple<int, int, int>> q;
	q.push({ 0, row, col }); // 처음 아기 상어 시작 0. 

	int eat_cnt = 0;
	int cur_dis = 0, cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while(1){
		if (q.size() == 0) break;

		while (q.size()) {
			tie(cur_dis, cur_row, cur_col) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];

				if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
				if (visited[next_row][next_col] != -1) continue;
			
				if (grid[next_row][next_col] <= shark_size ) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1; // 방문처리
					q.push({ cur_dis + 1, next_row, next_col });
					// 빈칸이거나 아기 상어와 크기가 같은 상어 칸은 통과만 가능. 
					if (grid[next_row][next_col] == 0 || grid[next_row][next_col] == shark_size) continue;

					// 잡아 먹었다. 상어 크기 업데이트 조건 만족시 키우고, 방문배열 초기화.
					shark_v.push_back({ cur_dis + 1, next_row, next_col });
				}
			}
		}

		if (shark_v.size()) {
			eat_cnt++;
			if (eat_cnt == shark_size) {
				shark_size++;
				eat_cnt = 0;
			}

			sort(shark_v.begin(), shark_v.end()); // 정렬. 거리 -> row -> col 순으로 오름차순 정렬.
			int d = 0, r = 0, c = 0;
			tie(d, r, c) = shark_v[0];
			grid[r][c] = 0; // 물고기 잡아먹어서 빈칸으로. 
			res += d;
			fill(&visited[0][0], &visited[0][0] + (24 * 24), -1); // 방문 배열 초기화

			// 새롭게 아기상어의 시작위치를 큐에 채워주고 시작 거리는 0.  
			q.push({ 0, r, c });
			visited[r][c] = 0; // 초기 시작위치 0.
			shark_v.clear(); // 잡아 먹을 수 있는 물고기 벡터 비워주기.
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 9) {
				baby_shark = { i, j }; // 아기상어 위치
				grid[i][j] = 0; // 아기상어는 어차피 움직이는 주체니까 움직이면 빈공간.
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 24 * 24, -1);
	solve_bfs(baby_shark.first, baby_shark.second);

	cout << res << "\n";
	return 0;
}