// https://www.acmicpc.net/problem/1520
// bfs + dp(중복 제외 -> 우선순위 큐)를 이용하는 복합적인 문제였다!!!

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> P; // grid[][], 행, 열 

int m = 0, n = 0, grid[504][504] = { 0, }, dp[504][504] = { 0, };
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = { 1, -1, 0, 0 };

// dp 배열로 방문처리도 하고 중복되는 것은 제외(우선순위 큐를 통해 중복을 방지).
priority_queue<P, vector<P>, less<P>> pq; //priority queue(자료형, 구현체, 비교연산자(=less)) greater는 최소힙
int solve_bfs_dp() {
	// 기저사례
	dp[0][0] = 1;
	pq.push({ grid[0][0], 0, 0 });

	// 로직 구현
	int info = 0, cur_row = 0, cur_col = 0;
	while (pq.size()) {
		tie(info, cur_row, cur_col) = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n) continue;
			if (grid[next_row][next_col] >= info) continue;

			// 중복 제외 (이미 방문처리가 된 곳은 pq에 넣지 않고, 경우의수를 더해주기만 하자.)
			if (dp[next_row][next_col] == 0) {
				pq.push({ grid[next_row][next_col], next_row, next_col });
			}
			dp[next_row][next_col] += dp[cur_row][cur_col];
		}
	}
	return dp[m - 1][n - 1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cout << solve_bfs_dp() << "\n";

	return 0;
}