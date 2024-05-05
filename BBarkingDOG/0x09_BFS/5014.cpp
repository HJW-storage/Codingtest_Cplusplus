// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define stair_max 1'000'004

int F = 0, S = 0, G = 0, U = 0, D = 0, visited_stair[stair_max] = { 0, };

int solve_bfs(int &up, int &down) {
	visited_stair[S] = 1; // 초기 방문처리
	queue<int> q;
	q.push(S);

	int pos_idx[2] = { up, -down };
	int cur_pos = 0, next_pos = 0;
	while (q.size()) {
		cur_pos = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			next_pos = cur_pos + pos_idx[i];

			if (next_pos < 1 || next_pos > F) continue;
			if (visited_stair[next_pos] > 0) continue; // 이미 방문 했던 곳.

			visited_stair[next_pos] = visited_stair[cur_pos] + 1;
			q.push(next_pos);
		}
	}

	return visited_stair[G]-1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> F >> S >> G >> U >> D;

	int res = solve_bfs(U, D);
	if (res == -1) cout << "use the stairs" << "\n";
	else cout << res << "\n";

	return 0;
}

/*
TC-1 
시작 위치와 도작 위치가 같은 경우,
<input>
10 10 10 2 1
<output>
0

TC-2
<input>
100 2 1 100 100
<output>
0

TC-3
<input>
100 2 1 100 1
<output>
1
*/