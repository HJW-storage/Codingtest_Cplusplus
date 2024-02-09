//https://www.acmicpc.net/problem/3197
// 시간초과 ..... 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n = 0, m = 0;
char grid[1504][1504];
int visited[1504][1504];	// 방문 배열
vector<vector<int>> check_pass_visited(1504, vector<int>(1504, 0));	// 방문 배열
vector<pair<int, int>> bbakjo;	// 백조 2마리 인덱스 저장할 pair 벡터.
vector<pair<int, int>> search_v;
vector<pair<int, int>> tmp_v;
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
int mem_row = 0, mem_col = 0;

bool check_pass_bfs(int start_row, int start_col, int end_row, int end_col) {
	check_pass_visited[start_row][start_col] = 1; // 방문처리
	queue<pair<int, int>> q;
	q.push({ start_row, start_col });
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;

	bool stop_flag = false;
	while (q.size()) {
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			// 검사
			if (next_row == end_row && next_col == end_col) {
				stop_flag = true;
				return stop_flag;
			}
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (grid[next_row][next_col] == '.' && check_pass_visited[next_row][next_col] == 0) {
					check_pass_visited[next_row][next_col] = 1; // 방문 처리
					q.push({ next_row, next_col });
				}
			}
		}
	}
	mem_row = cur_row;
	mem_col = cur_col;
	return stop_flag;
}
int solve(vector<pair<int, int>>& bbakjo) {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	int cnt = 0;

	while (1) {
		tmp_v.reserve(1504);
		bool check_flag = check_pass_bfs(mem_row, mem_col, bbakjo[1].first, bbakjo[1].second);
		//cout << check_flag << "\n";
		if (check_flag == true) break;

		for (pair<int, int> it : search_v) {
			cur_row = it.first;
			cur_col = it.second;
			visited[cur_row][cur_col] = 1; // 방문처리
			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					if (visited[next_row][next_col] == 0 && grid[next_row][next_col] == 'X') {
						visited[next_row][next_col] = 1; // 방문처리
						tmp_v.push_back({ next_row, next_col });
					}
				}
			}
		}

		search_v.clear(); // 초기화
		search_v.reserve(1504);
		for (pair<int, int> it : tmp_v) {
			// search_v에 복사하고, grid '.'으로 바꾸기
			grid[it.first][it.second] = '.'; // 물 공간으로 바꿔주기.
			search_v.push_back({ it.first, it.second });
		}
		tmp_v.clear();
		cnt++;

		/*cout << "\n\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}*/

	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	tmp_v.reserve(1504);
	search_v.reserve(1504);
	// 빈칸 없이 입력으로 들어오는 문자열 입력 받기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if (grid[i][j] == 'L') bbakjo.push_back({ i, j });	// 벡조 인덱스 저장.
			else if (grid[i][j] == '.') search_v.push_back({ i, j }); // 탐색할 위치 저장.
		}
	}
	/*cout << "백조_1 idx : " << bbakjo[0].first << " " << bbakjo[0].second << "\n";
	cout << "백조_2 idx : " << bbakjo[1].first << " " << bbakjo[1].second << "\n";*/

	int result = 0;
	if (bbakjo.size() >= 2) {
		mem_row = bbakjo[0].first;
		mem_col = bbakjo[0].second;
		result = solve(bbakjo);
		cout << result << "\n";
	}
	else {
		cout << result << "\n";
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}*/
	return 0;
}