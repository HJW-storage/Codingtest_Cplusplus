// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int  n = 0;
int grid[30][30] = { 0, }, visited[30][30] = {0, };
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
int total_home_cnt = 0;
vector<int> res;

void solve_bfs(int row, int col) {
	visited[row][col] = 1; // 초기 방문처리
	queue<pair<int, int>> q;
	q.push({ row, col });
	int home_cnt = 1;

	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + dr[i];
				int next_col = cur_col + dc[i];
				if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
				if (visited[next_row][next_col] || grid[next_row][next_col] == 0) continue;
				visited[next_row][next_col] = 1; //방문처리
				home_cnt++; 
				q.push({ next_row, next_col });
			}
		}
	}
	res.push_back(home_cnt);
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	// int 자료형 공백없이 입력되는 경우.
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			grid[i][j] = tmp[j] - '0';	// 정수로 저장. 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] || grid[i][j] == 0) continue;
			solve_bfs(i, j);
			total_home_cnt++;
		}
	}

	// 오름차순 정렬하기
	sort(res.begin(), res.end());
	// 결과 출력
	cout << total_home_cnt << "\n";
	for (int it : res) {
		cout << it << "\n";
	}

	return 0;
}
