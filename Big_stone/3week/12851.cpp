//https://www.acmicpc.net/problem/12851

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define last_idx 100100

using namespace std;
int n = 0, k = 0, min_res = 0, min_cnt = 0;
int visited[last_idx] = { 0, };	// 방문처리 배열
int cnt[last_idx] = { 0, };	

void solve_bfs(int subin_x) {
	const int dx[3] = { -1, 1, 99 };	// 99는 이후 조건문으로 x*2로 표현
	visited[subin_x] = 1;	//  초기 방문처리
	cnt[subin_x] = 1;
	queue<int> q;
	q.push(subin_x);
	
	int cur_x = 0, next_x = 0;
	while (q.size() != 0) {
		int cur_x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2) { next_x = 2 * cur_x; }
			else { next_x = cur_x + dx[i]; }

			if (next_x >= 0 && next_x < last_idx) {
				if (visited[next_x] == 0) {
					q.push(next_x);
					visited[next_x] = visited[cur_x] + 1;
					cnt[next_x] += cnt[cur_x];
				}
				else if (visited[next_x] == visited[cur_x] + 1) {
					cnt[next_x] += cnt[cur_x];
				}
				else { ; }
			}

		}
	}
	min_res = visited[k] - 1;
	min_cnt = cnt[k];
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	
	// bfs 구현
	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";
	}
	else {
		solve_bfs(n);
		cout << min_res << "\n";
		cout << min_cnt << "\n";
	}
	return 0;
}