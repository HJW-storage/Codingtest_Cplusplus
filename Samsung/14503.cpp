// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n = 0, m = 0, grid[54][54] = { 0, }, visited[54][54] = { 0, }, res = 0;
int start_row = 0, start_col = 0, start_dir = 0;
// "0" : 북쪽,
// "1" : 동쪽, 
// "2" : 남쪽, 
// "3" : 서쪽
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void Q_Clear(queue<tuple<int, int, int>> &tq) {
	queue<tuple<int, int, int>> empty_q;
	swap(tq, empty_q);
	return;
}

void solve_bfs(int row, int col, int dir) {
	visited[row][col] = 1; // 방문처리 - 청소완료
	res += 1;

	queue<tuple<int, int, int>> q;
	q.push({ row, col, dir });

	queue<tuple<int, int, int>> tmp_Q;

	int cur_row = 0, cur_col = 0, cur_dir = 0, next_row = 0, next_col = 0, next_dir = 0;
	while (q.size()) {
		tie(cur_row, cur_col, cur_dir) = q.front();
		q.pop();

		int tmp_dir = cur_dir;
		// 주변 4칸 청소되지 않은 빈칸이 있는지 검사한다.
		for (int i = 0; i < 4; i++) { // 4방향 돌리는데, 현재 바라보고 있는 방향을 기준으로 반시계 방향으로 돌린다.
			
			/*
			next_dir = tmp_dir--;  이렇게 써서 비버깅 꽤 오래했다...  후위 연산은 다음 줄에서 -- 되는것이다...
			next_dir = --tmp_dir;  전위 연산은 먼저 -- 하고 대입.
			*/
			next_dir = --tmp_dir; 
			if (next_dir < 0) next_dir += 4;

			next_row = cur_row + dr[next_dir];
			next_col = cur_col + dc[next_dir];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == 0) {
				tmp_Q.push({ next_row, next_col, next_dir });
			}

		}

		// 청소할 칸이 있는지 tmp_Q 크기를 통해 알 수 있다.
		if (tmp_Q.size()) {
			// 현재 dir을 기준으로 반시계로 검사했기에 가장 앞에 있는것을 청소한다.
			tie(next_row, next_col, next_dir) = tmp_Q.front();
			visited[next_row][next_col] = 1; // 방문처리 = 청소
			res++;
			q.push({ next_row, next_col, next_dir }); // 다음 큐 방문시작 위치 push.
			Q_Clear(tmp_Q); // 큐 비우기.
		}
		// 청소할 칸이 없는 경우는 
		else {
			// 방향 유지한채로 후진. -> 이동은 반대 방향으로 하는 것이다.
			
			int move_dir = (cur_dir - 2 < 0 ? cur_dir - 2 + 4 : cur_dir - 2);
			next_row = cur_row + dr[move_dir];
			next_col = cur_col + dc[move_dir];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) break;
			if (grid[next_row][next_col] == 0) {
				q.push({ next_row, next_col, cur_dir }); // 방향은 기존 방향을 넣어준다.
			}
			else {
				break;
			}
		}

	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	cin >> start_row >> start_col >> start_dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	solve_bfs(start_row, start_col, start_dir);
	cout << res << "\n";
	
	return 0;
}