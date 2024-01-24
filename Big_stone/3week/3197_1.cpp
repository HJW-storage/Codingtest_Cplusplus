//https://www.acmicpc.net/problem/3197
// 시간초과 ..... 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define max_n 1504

using namespace std;
int n = 0, m = 0;
char grid[max_n][max_n];
int visited_water[max_n][max_n];
int visited_bbakjo[max_n][max_n];
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> bbakjo;
queue<pair<int, int>> bbakjo_q, bbakjo_tmpq;
queue<pair<int, int>> water_q, water_tmpq;

// 큐 비우기
void Qclear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> emptyq;
	swap(q, emptyq);
}
// 빙판 녹이기 (grid[][] 값을 변경시킨다.)
void melting() {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (water_q.size()) {
		cur_row = water_q.front().first;
		cur_col = water_q.front().second;
		water_q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (visited_water[next_row][next_col] == 0 && grid[next_row][next_col] == 'X') {
					visited_water[next_row][next_col] = 1; // 방문 처리
					grid[next_row][next_col] = '.'; // 빙판 녹이기. 
					water_tmpq.push({ next_row, next_col });
				}
			}
		}
	}

	// tmpq 복사해주기
	water_q = water_tmpq;
	Qclear(water_tmpq);	// 큐 비우기
	return;
}
// 백조가 만나는지 검사 (grid[][] 값을 변경시키지 않고 검사만한다.)
bool bbakjo_meet(int end_row, int end_col) {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (bbakjo_q.size()) {
		cur_row = bbakjo_q.front().first;
		cur_col = bbakjo_q.front().second;
		bbakjo_q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			
			// 검사 (백조 만나면 탈출)
			if (next_row == end_row && next_col == end_col) {
				return true;
			}

			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (visited_bbakjo[next_row][next_col] == 0) {
					if (grid[next_row][next_col] == '.') {
						bbakjo_q.push({ next_row, next_col }); // 물인 곳은 지나간다.
						visited_bbakjo[next_row][next_col] = 1; // 방문처리
					}
					else if (grid[next_row][next_col] == 'X') {
						bbakjo_tmpq.push({ next_row, next_col }); // 다음 백조 탐색 위치 추가
						visited_bbakjo[next_row][next_col] = 1; // 방문처리
					}

				}
			}
		}
	}
	// tmpq 복사해주기
	bbakjo_q = bbakjo_tmpq;
	Qclear(bbakjo_tmpq);	// 큐 비우기
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 빈칸 없이 입력되는 문자열
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if (grid[i][j] == 'L') {
				bbakjo.push_back({ i, j });	// 벡조 인덱스 저장.
			}
			// 백조가 있는 위치도 물이기에 백조위치도 water_Q에 넣어야하가이
			// else if로 쓰면 안된다.
			if (grid[i][j] == '.' || grid[i][j] == 'L') {
				water_q.push({ i, j }); // 물인 곳 탐색할 위치 저장.
				visited_water[i][j] = 1;	// 초기 방문처리
			}
		}
	}
	bbakjo_q.push({ bbakjo[0].first, bbakjo[0].second});
	visited_bbakjo[bbakjo[0].first][bbakjo[0].second] = 1; // 초기 방문처리

	int result = 0;
	if (bbakjo.size() >= 2) {
		while (1) {
			bool stop_flag = bbakjo_meet(bbakjo[1].first, bbakjo[1].second);
			if (stop_flag == true) break;
			melting();
			result++;
		}
		cout << result << "\n";
	}
	else {
		cout << result << "\n";
	}
	return 0;
}