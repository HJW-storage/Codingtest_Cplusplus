// https://www.acmicpc.net/problem/4485

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define max_n 130
#define mx_cost 987654321

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

int n = 0, grid[max_n][max_n] = { 0, }, cost[max_n][max_n] = { 0, };

int solve_bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	cost[0][0] = grid[0][0]; // 초기조건

	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (q.size()) {
		tie(cur_row, cur_col) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
			if (cost[next_row][next_col] > cost[cur_row][cur_col] + grid[next_row][next_col]) {
				q.push(make_pair(next_row, next_col));
				cost[next_row][next_col] = cost[cur_row][cur_col] + grid[next_row][next_col]; // 최소값으로 업데이트.
			}
		}
	}

	return cost[n-1][n-1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int test_case = 0;

	while (1) {
		cin >> n;
		if (n == 0) break;	// 종료 조건.

		// 테스트 케이스마다 초기화 진행.
		fill(&grid[0][0], &grid[0][0] + max_n * max_n, 0);
		fill(&cost[0][0], &cost[0][0] + max_n * max_n, mx_cost); // 최대값으로 초기화.


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		test_case++;
		cout << "Problem " << test_case << ": " << solve_bfs() << "\n";
	}

	return 0;
}