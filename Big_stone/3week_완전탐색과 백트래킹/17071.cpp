//https://www.acmicpc.net/problem/17071

#include <iostream>
#include <algorithm>
#include <queue>

#define max_idx 500004
using namespace std;

int subin_pos = 0, sister_pos = 0, res_min_sec = 0, turn = 1;
int visited[2][max_idx];	// 홀수, 짝수에 해당하는 방문 배열 생성.
bool ok = false;

int solve_bfs(int x) {
	visited[0][x] = 1; // 초기 방문처리
	queue<int> q;
	q.push(x);

	while (q.size()) {
		sister_pos += turn;
		if (sister_pos > 500000) return -1;
		// 수빈이가 -1, +1이 있으므로 제자리로 올 수 있다. 
		// 따라서, 동생 최종 turn - 2 번째에 미리 동생 위치에 있었다면 만날 수 있다.
		// 이것을 표현하고자 visited 방문 배열을 홀수, 짝수 나눠서 만듦.
		if (visited[turn % 2][sister_pos] != 0) {
			ok = true;
			break;
		}

		// bfs의 깊이를 세야하는 경우 q.size를 통해 for문에 for문을 돌린다.
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int cur_x = q.front();
			q.pop();
			for (int next_x : {cur_x + 1, cur_x - 1, 2 * cur_x}) {
				if (next_x >= 0 && next_x <= 500000) {
					if (visited[turn % 2][next_x] == 0) {
						visited[turn % 2][next_x] = visited[(turn + 1) % 2][cur_x] + 1;
						
						q.push(next_x);
						
						if (next_x == sister_pos) {
							ok = true;
							break;
						}
					}

				}
			}
			if (ok == true) break;
		}
		if (ok == true) break;
		turn++;
	}

	if (ok == true) { return turn; }
	else { return -1; }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> subin_pos >> sister_pos;	// n : 수빈 , k : 동생 위치 
	if (subin_pos == sister_pos) {
		cout << "0" << "\n";
	}
	else {
		int result = solve_bfs(subin_pos);
		cout << result << "\n";
	}
	return 0;
}