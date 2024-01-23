// https://www.acmicpc.net/problem/14497
// 풀이시간 1시간. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n = 0, m = 0, junan_row = 0, junan_col = 0, dest_row = 0, dest_col = 0;
char grid[304][304];
int visited[304][304];
vector<pair<int, int>> tmp_v;

int solve_bfs(int row, int col) {
	visited[row][col] = 1; // 초기 방문처리
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = {1, 0, -1, 0};
	queue<pair<int, int>> q;
	q.push({row, col});

	int result = 0;
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	bool stop_flag = false;

	// 단순히 가장 가까운 거리만 탐색하는게 아니다. 
	// 한 겹의 친구를 쓰러뜨려야하므로 상하좌우 '0'인 곳은 큐에 계속 채우면서 
	// '1'인 곳은 큐에 채우지 않으면서, 추가로 다음번에 bfs 시작하는 위치로 지정하기 위해 임시 벡터(tmp_v)에 저장한다. 
	// 단, 방문처리는 모두 해줄 것.
	// 그러면, 방문처리를 해주기 때문에 친구들의 한 겹에 '1' 테두리에 막히면서 '0'을 다 탐색하여 큐는 비기때문에 while(q.size())는 종료된다. 
	while (1) {
		tmp_v.clear(); // 초기화

		// 탈출 조건 명시해야한다.
		while (q.size()) {
			cur_row = q.front().first;
			cur_col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];

				// 탈출 조건. 초코바 발견!!
				if (next_row == (dest_row - 1) && next_col == (dest_col - 1)) {
					stop_flag = true;
					break;
				}

				// 로직 구현
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					// '0'인 곳은 방문처리하고 q 큐에 채우기
					if (grid[next_row][next_col] == '0' && visited[next_row][next_col] == 0) {
						visited[next_row][next_col] = 1; // 방문처리
						q.push({next_row, next_col});
					}
					// '1'인 곳은 방문처리만 해줄 것. 큐에 채우지 않는다. 
					else if (grid[next_row][next_col] == '1' && visited[next_row][next_col] == 0) {
						visited[next_row][next_col] = 1; // 방문처리
						tmp_v.push_back({ next_row, next_col }); // 다음번 bfs 시작할 위치로 지정하기 위해 임시 벡터에 채운다.
					}
				}
			}
			if (stop_flag == true) break; // 탈출
		}
		if (stop_flag == true) break; // 탈출

		// 위쪽 탐색 완료한 뒤, 큐가 비어 있는 상태. 상하좌우로 갈 수 있는 0은 다 갔다온 상태.
		// 벡터에 저장된 좌표들 큐에 넣고, grid 좌표 '0'으로 바꿔주기. 
		for (pair<int, int> it : tmp_v) {
			q.push({ it.first, it.second }); // 벡터에 저장된 좌표들 큐에 넣고
			grid[it.first][it.second] = '0'; // grid 좌표 '0'으로 바꿔주기.
		}
		result++;
	}
	return result + 1;	// 마지막 result++ 전에 탈출했으므로 +1을 해준다. 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 빈칸 없이 입력들어오는 수 입력 받기
	cin >> n >> m;
	cin >> junan_row >> junan_col >> dest_row >> dest_col;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
		}
	}
	
	// 주난이와 초코바 위치는 1,1 을 기준으로한 좌표이므로 
	// grid와 맞추기 위해 -1씩 해주자. 
	int result_cnt = solve_bfs(junan_row - 1, junan_col - 1);
	cout << result_cnt << "\n";

	return 0;
}