// https://softeer.ai/practice/6281

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int n = 0, m = 0, grid[104][104] = { 0, }, visited[104][104] = { 0, };

void Qclear(queue<pair<int, int>> &tq) {
	queue<pair<int, int>> emptyq;
	swap(tq, emptyq);
}
int solve_bfs(int row, int col) {
	// bfs로 돌리면서 얼음으로 되어 가지 못하는 경우는 
	// 큐에 넣지않고 해당 얼음 위치에 방문 표시만 해둔다. 방문표시는 누적한다.
	// 2 이상인 얼음은 다음 탐색 시작 시점이므로 큐에 넣어두고 사용하자.
	
	visited[row][col] = 1; // 방문처리
	queue<pair<int, int>> q;
	q.push({ row, col });

	queue<pair<int, int>> tmpq;
	int time_cnt = 0;
	while(1){
		while (q.size()) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			// 맨 처음 초기 bfs는 주어진 배열 가장자리부터 얼음 덩어리의 가장 모서리 부분까지만 탐색.
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + dr[i];
				int next_col = cur_col + dc[i];

				if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
				if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = 1; // 방문처리
					q.push({ next_row, next_col }); // 기존 큐에 추가
				}
			
				// 맨 처음 bfs가 끝나고 2번쨰 bfs 부터는 기존에 방문 1이 었던 곳이 2가 되면서 그 다음 시간에
				// 없어질 얼음이 업데이트 된다.
				if (grid[next_row][next_col] == 1) { // 여기가 핵심 부분이다.
					// 얼음인 경우에는 묻지고 따지지도 말고 방문배열 방문표시를 +1씩 해준다.
					// 방문 표시가 2가 된다면 해당 얼음은 녹은 걸로 바꿔주고, 다음 bfs 시작을 위한 
					// 임시 큐(tmpq) <주의!! 기존 q에 넣으면 안된다. 임시큐에 넣자.>에 넣어준다. 
					visited[next_row][next_col] = visited[next_row][next_col] + 1;
					if (visited[next_row][next_col] == 2) {
						tmpq.push({ next_row, next_col });
						grid[next_row][next_col] = 0; // 얼음 녹았다. 
					}
				}
			}
		}

		// 종료조건
		if (tmpq.size() == 0) break;

		time_cnt++;

		q = tmpq; // 큐 복사
		Qclear(tmpq); // 큐 비우기
	}
	return time_cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	// 가장자리에는 얼음이 생기지 않는다고 명시되있다. (0,0)부터 시작.
	cout << solve_bfs(0, 0) << "\n";
	return 0;
}