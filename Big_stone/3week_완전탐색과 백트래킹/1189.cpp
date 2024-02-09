// https://www.acmicpc.net/problem/1189

// 1. dfs로 깊이 탐색
// 2. 조건에 종료 지점(한수의 집)에서 지금까지온 거리가 k가 아니라면 접근 못하고 우회하게 한다.
// 3. 만약, k인 거리에 오는 경우의 수가 없다면 0을 출력하게 한다.

#include <iostream>
#include <algorithm>

using namespace std;
int n = 0, m = 0, k = 0, res = 0, dis = 1; // 초기 시작점 부터 거리 1로 계산하므로 초기값을 1로 한다..
char way[10][10];
int visited[10][10];
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

void solve_dfs(int row, int col) {
	visited[row][col] = 1; // 방문처리

	// 출력 찍어보기
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "현재 dis : " << dis << " , 현재 res : " << res << "\n";*/

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (way[next_row][next_col] != 'T' && visited[next_row][next_col] == 0) {
				if (next_row == 0 && next_col == m - 1) {	// 집도착. 거리 k인지 검사
					if (dis + 1 != k) {	// 거리 K보다 더 짧은 시간으로 도착하는 것을 막는 경우
						continue;
					}
					else if(dis + 1 == k){	// 조건 만족으로 결과 카운팅 +1 해주고 dfs 실행하지 않음.
						res++; // 결과값 +1.
						continue;
					}
				}
				else {
					if (dis + 1 >= k) {	// 집 도착 이전에 거리 k가 이미 되어 버린 초과된 상태를 제외하는 경우.
						continue;
					}
				}
				dis++;
				solve_dfs(next_row, next_col);
				dis--; // 복구
				visited[next_row][next_col] = 0; // 복구 
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> way[i][j];
		}
	}
	solve_dfs(n - 1, 0);

	cout << res << "\n";
	return 0;
}