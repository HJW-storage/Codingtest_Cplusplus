// https://www.acmicpc.net/problem/6593
// 입력에서 시작 start 좌표를 row, col, hei가 제대로 입력이 안되어서 디버깅한 부분이다... 
// 되도록 행은 r로 쓰고, 열은 c로, 높이는 h로 써서 눈에 잘띄게 하자....

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int L = 0, R = 0, C = 0;
char grid[34][34][34];
int visited[34][34][34] = { 0, };

const int dr[6] = { -1, 0, 1, 0, 0, 0 };
const int dc[6] = { 0, 1, 0, -1, 0, 0 };
const int dh[6] = { 0, 0, 0, 0, 1, -1 };

int solve_bfs(int row, int col, int hei) {
	visited[row][col][hei] = 1; // 초기 방문처리
	queue<tuple<int, int, int>> q;
	q.push({row, col, hei});

	int cur_row = 0, cur_col = 0, cur_hei = 0, next_row = 0, next_col = 0, next_hei = 0;
	while (q.size()) {
		tie(cur_row, cur_col, cur_hei) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			next_hei = cur_hei + dh[i];

			// '.', 'E'는 지나갈 수 있는 칸이다. = '#'이 아니면 지나간다.
			if (next_row < 0 || next_row >= R || next_col < 0 || next_col >= C || next_hei < 0 || next_hei >= L) continue;
			if (visited[next_row][next_col][next_hei] > 0) continue; // 방문했언던 경우. 
			
			if (grid[next_row][next_col][next_hei] != '#') {
				visited[next_row][next_col][next_hei] = visited[cur_row][cur_col][cur_hei] + 1; // 방문처리
				q.push({ next_row, next_col, next_hei });

				if (grid[next_row][next_col][next_hei] == 'E') {
					// 마지막에 -1해서 return.
					return (visited[next_row][next_col][next_hei] - 1);
				}
			}
		}
	}

	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 여러 테스트 케이스 입력
	while (1) {
		// 초기화
		fill(&visited[0][0][0], &visited[0][0][0] + 34 * 34 * 34, 0);
		fill(&grid[0][0][0], &grid[0][0][0] + 34 * 34 * 34, 'a');

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break; // 테스트 케이스 종료.

		// grid 입력
		int start_r = 0, start_c = 0, start_h = 0;
		for (int h = 0; h < L; h++) {
			for (int r = 0; r < R; r++) {
				string tmp;
				cin >> tmp;
				for (int c = 0; c < C; c++) {
					grid[r][c][h] = tmp[c];
					// bfs 시작 위치 저장.
					if (grid[r][c][h] == 'S') {
						start_h = h;
						start_r = r; 
						start_c = c;
					}
				}
			}
		}

		int res = solve_bfs(start_r, start_c, start_h);
		if (res != 0) {
			cout << "Escaped in " << res << " minute(s)." << "\n";
		}
		else {
			cout << "Trapped!" << "\n";
		}
	}
	return 0;
}