// https://www.acmicpc.net/problem/12869

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int hp[3] = { 0, };
int visited[64][64][64];
int n = 0, result = 0;
int attack[6][3] = {
	{1, 3, 9},
	{1, 9, 3},
	{3, 1, 9},
	{3, 9, 1},
	{9, 1, 3},
	{9, 3, 1}
};

int solve_bfs(int hp1, int hp2, int hp3) {
	visited[hp1][hp2][hp3] = 1; // 방문처리
	queue<tuple<int, int, int>> q;
	q.push({ hp1, hp2, hp3 });
	while (q.size()) {
		int cur_hp1 = get<0>(q.front());
		int cur_hp2 = get<1>(q.front());
		int cur_hp3 = get<2>(q.front());
		q.pop();
		if (visited[0][0][0] != 0) break;
		int next_hp1 = 0;
		int next_hp2 = 0;
		int next_hp3 = 0;
		for (int i = 0; i < 6; i++) {
			next_hp1 = max(0, cur_hp1 - attack[i][0]);
			next_hp2 = max(0, cur_hp2 - attack[i][1]);
			next_hp3 = max(0, cur_hp3 - attack[i][2]);
			if(visited[next_hp1][next_hp2][next_hp3] == 0){
				visited[next_hp1][next_hp2][next_hp3] = visited[cur_hp1][cur_hp2][cur_hp3] + 1;
				q.push({ next_hp1, next_hp2, next_hp3 });
			}
		}
	}
	return visited[0][0][0] - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hp[i];
	}
	result = solve_bfs(hp[0], hp[1], hp[2]);
	cout << result << "\n";

	return 0;
}