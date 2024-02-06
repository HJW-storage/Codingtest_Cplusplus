// https://www.acmicpc.net/problem/10026

// 1. dfs 이용
// 2. 적록색약 환자 R = G 같다고 생각하고 BFS 탐색.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n = 0, normal_p = 0, ill_p = 0;
int visited[105][105];
vector<vector<char>> normal_grid(105, vector<char>(105, ' '));
vector<vector<char>> ill_grid(105, vector<char>(105, ' '));
//char normal_grid[105][105], ill_grid[105][105];
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

void solve_dfs(int row, int col, vector<vector<char>> &grid) {
	visited[row][col] = 1; // 방문처리
	char initail_ch = grid[row][col]; // 탐색 시작시 기준이 되는 처음 색상.

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
		if (visited[next_row][next_col]) continue;
		if (grid[next_row][next_col] != initail_ch) continue;
		solve_dfs(next_row, next_col, grid);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	char tmp = ' ';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			normal_grid[i][j] = tmp;
			// 적록 색약인 사람이 보는 그림은 R = G로 보기에 G도 R로 저장하자.
			if (tmp == 'G') {
				ill_grid[i][j] = 'R';
			}
			else {
				ill_grid[i][j] = tmp;
			}
		}
	}

	// 정상인 사람 먼저 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			solve_dfs(i, j, normal_grid);
			normal_p++;
		}
	}

	// 적록색약 사람 탐색. (이전에 탐색해서 visited배열 초기화 해주자.)
	fill(&visited[0][0], &visited[0][0] + 105*105, 0); // 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			solve_dfs(i, j, ill_grid);
			ill_p++;
		}
	}

	// 결과 출력
	/*cout << "정상인 : " << normal_p << "\n";
	cout << "적록색약인 : " << ill_p << "\n";*/
	cout << normal_p << " " << ill_p << "\n";
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}*/

	return 0;
}
/*
2
R G
B R
*/