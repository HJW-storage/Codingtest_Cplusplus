// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

int n = 0, m = 0, k = 0; // n : 행, m : 열
int grid[1004][1004] = { 0, };
int visited[1004][1004][11] = { 0, };

int solve_bfs() {
	//  (1, 1)과 (N, M)은 항상 0이라고 가정하자.
	visited[1][1][0] = 1; // 방문 처리

	// {행, 열, 벽을 부쉈는지 확인하는 flag, 거리}
	queue<tuple<int, int, int, int>> q;
	q.push({ 1, 1, 0, 1 });

	int cur_row = 0, cur_col = 0, wall_break = 0, cur_dist = 0;
	int next_row = 0, next_col = 0;
	int min_res = 1'000'004;

	while (q.size()) {
		tie(cur_row, cur_col, wall_break, cur_dist) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 1 || next_row > n || next_col < 1 || next_col > m) continue;
			if (wall_break > k) continue; // 벽 부수기는 최대 k번 까지만 가능하다. 

			// 아래 나눈 기준을 하나로 합쳐서 표현할 수 있다.
			if (wall_break >= 0) {
				if (visited[next_row][next_col][wall_break] == 0 && grid[next_row][next_col] == 0) {
					visited[next_row][next_col][wall_break] = 1; // 방문처리
					q.push({ next_row, next_col, wall_break, cur_dist + 1 });

					if (next_row == n && next_col == m) {
						min_res = min(min_res, cur_dist + 1);
						break;
					}
				}
				else if (visited[next_row][next_col][wall_break + 1] == 0 && grid[next_row][next_col] == 1) {
					visited[next_row][next_col][wall_break + 1] = 1; // 방문처리
					q.push({ next_row, next_col, wall_break + 1, cur_dist + 1 });
				}
			}

			/*
			if (wall_break == 0) {
				if (visited[next_row][next_col][0] == 0 && grid[next_row][next_col] == 0) {
					visited[next_row][next_col][0] = 1; // 방문처리
					q.push({ next_row, next_col, 0, cur_dist + 1 });

					if (next_row == n && next_col == m) {
						min_res = min(min_res, cur_dist + 1);
						break;
					}
				}
				else if (visited[next_row][next_col][wall_break+1] == 0 && grid[next_row][next_col] == 1) {
					visited[next_row][next_col][wall_break+1] = 1; // 방문처리
					q.push({ next_row, next_col, wall_break+1, cur_dist + 1 });
				}
			}
			// 벽을 부수고 온 경우. 
			else if (wall_break != 0) {
				if (visited[next_row][next_col][wall_break] == 0 && grid[next_row][next_col] == 0) {
					visited[next_row][next_col][wall_break] = 1; // 방문처리
					// 벽을 부수고 온 경우라는 표시로  wall_break (1)로 큐에 넣는다.
					q.push({ next_row, next_col, wall_break, cur_dist + 1 });

					if (next_row == n && next_col == m) {
						min_res = min(min_res, cur_dist + 1);
						break;
					}
				}
				else if (visited[next_row][next_col][wall_break + 1] == 0 && grid[next_row][next_col] == 1) {
					visited[next_row][next_col][wall_break + 1] = 1; // 방문처리
					q.push({ next_row, next_col, wall_break + 1, cur_dist + 1 });
				}
			}
			*/

		}
	}

	if (min_res == 1'000'004) min_res = -1;
	return min_res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= m; j++) {
			grid[i][j] = tmp[j - 1] - '0';
		}
	}

	//  (1, 1)과 (N, M)은 항상 0이라고 가정하자.
	//   n, m 이 1이면,  결과 : 1 출력.
	if (n == 1 && m == 1) {
		cout << "1" << "\n";
		return 0;
	}

	cout << solve_bfs() << "\n";

	return 0;
}

/*
6 4 1
0000
1110
1000
0000
0111
0000
res : 9

6 4 2
0110
1110
1000
0000
0111
0000
res : 9

6 4 2
0110
1110
1000
1000
0111
0000
res : -1

6 4 3
0011
1110
1000
1000
1111
0000
res : 9
*/