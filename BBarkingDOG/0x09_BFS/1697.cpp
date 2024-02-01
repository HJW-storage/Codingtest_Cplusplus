// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define max_n 100004
int n = 0, k = 0, res_time = 0;
int visited[max_n];

void solve_bfs(int here) {
	visited[here] = 1; // 수빈이 위치 초기 방문처리
	queue<int> q;
	q.push(here);
	bool stop_flag = false;
	while (q.size()) {
		int cur_idx = q.front();
		q.pop();
		for (int next_idx : {cur_idx + 1, cur_idx - 1, 2 * cur_idx}) {
			//cout << "next_idx : " << next_idx << "\n";
			if (next_idx < 0 || next_idx > max_n) continue;
			if (visited[next_idx]) continue;
			visited[next_idx] = visited[cur_idx] + 1;
			if (next_idx == k) {
				stop_flag = true;
				break;
			}
			q.push(next_idx);
		}
		if (stop_flag) break;
	}
	res_time = visited[k] - 1;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	// 입력
	cin >> n >> k; // n : 수빈이 위치, k : 동생의 위치
	if (n == k) {
		cout << "0" << "\n";
		return 0;
	}
	solve_bfs(n);
	cout << res_time << "\n";

	return 0;
}