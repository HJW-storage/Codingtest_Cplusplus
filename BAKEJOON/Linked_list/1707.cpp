// https://www.acmicpc.net/problem/1707

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K = 0, V = 0, E = 0;
bool flag = true;
int visited[20004]; // 방문처리, 검사

void solve_dfs(int u, int cur_color, vector<vector<int>> & linked) {
	visited[u] = cur_color; // 방문처리
	
	for (int i = 0; i < linked[u].size(); i++) {
		if (visited[linked[u][i]] == -1) {
			//solve_dfs(linked[u][i], cur_color ^= 1, linked);
			// 위에 처럼 쓰면 cur_color 값이 변해서 다음 for문에 영향을 준다... 
			// 삽질 엄청했따.... 비트 연산 쓰겠다고 깝치다가 .... 
			solve_dfs(linked[u][i], cur_color ^ 1 , linked);
		}
		/*else if (visited[liked[u][i]] == (cur_color ^= 1)) {
			continue;
		}*/
		else if (visited[linked[u][i]] == cur_color) {
			flag = false;
			return;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> K;
	while (K--) {
		cin >> V >> E;
		
		flag = true; // 초기화
		fill(&visited[0], &visited[0] + 20004, -1); // 초기화
		vector<vector<int>> linked(V+1); // 연결리스트 구현, 초기화.
		
		int u = 0, v = 0;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			linked[u].push_back(v);
			linked[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == -1) {
				solve_dfs(i, 0, linked);
			}
		}
		
		if (flag == true) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}