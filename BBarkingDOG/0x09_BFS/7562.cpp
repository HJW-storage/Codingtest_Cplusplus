// https://www.acmicpc.net/problem/7562

// bfs 변형. 
// 8방향. 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t = 0, n = 0, s_row = 0, s_col = 0, e_row = 0, e_col = 0, res = 0;
int visited[304][304] = { 0, };
const int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int solve_bfs(int row, int col, int end_row, int end_col) {
	visited[row][col] = 1; // 초기 방문처리
	queue<pair<int, int>> q;
	q.push({ row, col });

	bool stop_flag = false;
	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
			if (visited[next_row][next_col]) continue;
			visited[next_row][next_col] = visited[cur_row][cur_col] + 1; // 방문처리
			q.push({ next_row, next_col });

			// 도착지에 도달하면 종료하자
			if (next_row == end_row && next_col == end_col) {
				stop_flag = true;
				break;
			}
		}
		if (stop_flag) break;
	}
	if (stop_flag) { return visited[e_row][e_col] - 1; }
	else { return 0; }
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> t;

	// test 개수만큼 수행.
	for (int i = 0; i < t; i++) {
		fill(&visited[0][0], &visited[0][0] + 304 * 304, 0); // 테스트 케이스 별 방문배열 초기화
		cin >> n;	// 체스판 한변의 길이
		cin >> s_row >> s_col;	// 시작 위치(현재 위치)
		cin >> e_row >> e_col; // 도착 위치

		if (s_row == e_row && s_col == e_col) {
			res = 0;
		}
		else{
			res = solve_bfs(s_row, s_col, e_row, e_col);
		}
		//cout << "res : " << res << "\n";
		cout << res << "\n";
	}

	return 0;
}