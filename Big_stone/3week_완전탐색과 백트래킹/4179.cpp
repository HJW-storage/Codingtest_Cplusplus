// https://www.acmicpc.net/problem/4179

// bfs를 사용하는데 지훈이와 불을 동시에 bfs 하며 비교해야한다. 
// 가장자리 인덱스 0과 n,m에 갈때까지 불과 겹치지 않으며 탈출 / 아니면 탈출 불가.
// 불을 먼저 움직이고, 그다음에 지훈이를 움직인다.
// 지훈이가 bfs를 돌려보고, next_row와 next_col이 가장자리 인덱스 인지 확인해서 탈출 / 불가 판별.

// 복잡도 계산해보기. 

#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>

using namespace std;
int n = 0, m = 0, cnt = 1;
const int dr[4] = {0, 1, 0, -1};				
const int dc[4] = {1, 0, -1, 0};

vector<vector<char>> grid(1004, vector<char>(1004, '0')); // 메모리 최대 1000 X 1000 X 1 = 1,000,000 = 1MB
vector<vector<int>> fire_visited(1004, vector<int>(1004, 0)); // 4MB
vector<vector<int>> visited(1004, vector<int>(1004, 0)); // 4MB

// 큐로 구현.
queue<pair<int, int>> fire;	// 메모리 최대 1000 X 1000 X 8 = 8,000,000 = 8MB
queue<pair<int, int>> jihun; // 8MB

void fire_bfs(int row, int col) {
	int next_row = 0, next_col = 0;
	fire_visited[row][col] = 1; // 방문처리
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if(next_row >= 0 && next_row <n && next_col >= 0 && next_col < m){
			// if (grid[next_row][next_col] != '#') 처음에 해당 조건만 사용했더니 메모리 초과..... 
			// fire_visited 방문처리 없이 진행하면 큐에 중복되는 좌표가 계속 들어가서 메모리 초과.
			if (grid[next_row][next_col] != '#' && fire_visited[next_row][next_col] == 0) {
				grid[next_row][next_col] = 'F';
				fire_visited[next_row][next_col] = 1; // 방문처리
				fire.push({ next_row, next_col });
			}
		}
	}
}
void jihun_bfs(int row, int col) {
	int next_row = 0, next_col = 0;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == '.') {
				grid[next_row][next_col] = 'J';
				jihun.push({ next_row, next_col });
				visited[next_row][next_col] = visited[row][col] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력 받기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if (grid[i][j] == 'F') {
				fire.push({ i, j });
			}
			else if (grid[i][j] == 'J') {
				jihun.push({ i, j });
				visited[i][j] = 1; // 초기 위치 방문처리
			}
			else { ; }
		}
	}

	int fire_size = 0, fire_row = 0, fire_col = 0, jihun_size = 0, jihun_row = 0, jihun_col = 0;
	bool talchul = false;
	while(jihun.size() != 0){
		// 불 이동 로직 작성
		fire_size = fire.size();
		for (int i = 0; i < fire_size; i++) {
			fire_row = fire.front().first;
			fire_col = fire.front().second;
			fire.pop();	
			fire_bfs(fire_row, fire_col);
		}

		// 지훈이 이동 로직 작성
		jihun_size = jihun.size();
		for (int i = 0; i < jihun_size; i++) {
			jihun_row = jihun.front().first;
			jihun_col = jihun.front().second;
			if (jihun_row == 0 || jihun_row == n - 1 || jihun_col == 0 || jihun_col == m - 1) {
				talchul = true;
				break;
			}
			jihun.pop();
			jihun_bfs(jihun_row, jihun_col);
		}

		if (talchul == true) break;
	}

	if (talchul == true) {
		cout << visited[jihun_row][jihun_col] << "\n";
		//cout << cnt << "\n";
	}
	else {
		cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}