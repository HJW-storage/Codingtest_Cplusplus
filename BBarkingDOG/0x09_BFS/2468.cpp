// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define max_n 104
#define RAIN 1

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
int n = 0, hei = 0, grid[max_n][max_n] = { 0, }, visited[max_n][max_n] = {0,};
int res = 0;

void Rain_Dropped(int rain_hei) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] < rain_hei) visited[i][j] = RAIN; // 침수 표시
		}
	}
}
void solve_bfs(int row, int col) {
	visited[row][col] = 2; // 방문처리. 침수 표시랑 단지 구분하려고 2로 함.
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

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
			if (visited[next_row][next_col] > 0) continue;
			visited[next_row][next_col] = 1; // 방문처리
			q.push({ next_row, next_col });
		}

	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	

	for (int h = 1; h <= 100; h++) {
		// 시뮬레이션 진행. 
		// 초기화
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);

		Rain_Dropped(h); // 빗물 침수 시키기

		int cnt = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					solve_bfs(i, j);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}

	cout << res << "\n";
	return 0;
}

/*
TC-1
input : 
3
104 104 104
104 104 104
104 104 104
output : 
1
*/