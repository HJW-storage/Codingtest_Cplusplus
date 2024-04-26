// https://softeer.ai/practice/6282

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n = 0;
int grid[30][30] = { 0, }, visited[30][30] = { 0, };
const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
priority_queue<int, vector<int>, greater<int>> pq;

int solve_dfs(int row, int col) {
	int cnt_block = 1;
	visited[row][col] = 1; // 방문처리.

	int next_row = 0, next_col = 0;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];

		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
		if (visited[next_row][next_col] > 0 || grid[next_row][next_col] == 0) continue;

		cnt_block += solve_dfs(next_row, next_col);
	}
	
	return cnt_block;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			grid[i][j] = tmp[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] > 0 && visited[i][j] == 0) {
				pq.push(solve_dfs(i, j));
				cnt++;
			}
		}
	}

	// 출력
	cout << cnt << "\n";
	while (pq.size()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}

// test1
//5
//00000
//00000
//00000
//00000
//00000
//output : 0

// test2
//5
//11111
//11111
//11111
//11111
//11111
//output : 
//1
//25