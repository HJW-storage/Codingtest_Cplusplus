//https://www.acmicpc.net/problem/13913

#include <iostream>
#include <algorithm>
#include <queue>

#define max_idx 100004
using namespace std;

int n = 0, k = 0, res_min_sec = 0;
// 방문 배열에 pair<int, char>로 최소거리와 그 전의 어떤 연산으로 온건지의 정보를 남긴다.
pair<int, char> visited[max_idx]; // first : 최소 거리, second : 이전에 어떤 계산으로 왔는지.

// 연산 정보는 a, b, c로 구분해서 a는 +1, b는 -1, c는 *2로 부터 온 연산이다라는 것을 나타낸다.
void check_visited(int cur_x, int next_x, int i, queue<int> &q) {
	char prev_cal = ' ';
	if (i == 0) prev_cal = 'a';
	else if (i == 1) prev_cal = 'b';
	else if (i == 2) prev_cal = 'c';

	if (next_x >= 0 && next_x < max_idx) {
		// 한번 방문했던 곳은 더이상 방문하지 않으므로 a, b, c가 겹쳐서 덮어씌어지거나 하는 일은 없다.
		// 그렇기에 해당 a, b, c 정보를 통해 역추적하면 최소 거리를 온 경로를 알 수 있다.
		if (visited[next_x].first == 0) {
			visited[next_x].first = visited[cur_x].first + 1;	// 최소 거리
			visited[next_x].second = prev_cal;	// 최소 거리

			q.push(next_x);
		}
	}
}
void solve_bfs(int x) {
	visited[x] = { 1, 0 }; // 초기 방문처리
	const int dx[3] = { 1, -1, 99 };	// 99는 *2로 쓰이는 용도.
	queue<int> q;
	q.push(x);

	bool break_flag = false;
	int cur_x = 0, next_x = 0;
	while (q.size()) {
		cur_x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2) { next_x = 2 * cur_x; }
			else { next_x = cur_x + dx[i]; }

			check_visited(cur_x, next_x, i, q);
			
			if (next_x == k) {
				res_min_sec = visited[k].first - 1;
				break_flag = true;
				break;
			}
		}
		if (break_flag == true) break;
	}
	return;
}
// 연산 정보는 a, b, c로 구분해서 a는 +1, b는 -1, c는 *2로 부터 온 연산이기에
// a인 경우는 반대인 -1을,
// b인 경우는 반대인 +1을,
// c인 경우는 반대인 /2를 해준다.
void detect_path(int idx) {
	vector<int> path;
	path.push_back(idx);
	// visited[idx].first != 1 은 맨 처음 시작한 위치에 방문처리가 1로 되어있기 때문에 1로 해준 것이다.
	while (visited[idx].first != 1) {
		if (visited[idx].second == 'a') idx = idx - 1;
		else if (visited[idx].second == 'b') idx = idx + 1;
		else if (visited[idx].second == 'c') idx = idx / 2;

		path.push_back(idx);
	}

	// 역순으로 벡터에 저장했으므로 역순으로 출력한다. 
	for (int i = path.size() - 1; i >= 0;i--) {
		cout << path[i] << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	// n : 수빈 , k : 동생 위치 
	solve_bfs(n);
	cout << res_min_sec << "\n";
	detect_path(k); // 경로 출력. 
	return 0;
}