// https://www.acmicpc.net/problem/2533

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1'000'004

int n = 0, res = 0, node_cnt = 0;
vector<int> linked[MAX_N];
int visited[MAX_N];
int dp[MAX_N][2];

void solve_dfs(int node) {
	visited[node] = 1; // 방문 처리

	// 초기화
	dp[node][0] = 0; // 본인이 얼리어답터가 아니면 얼리 개수 0
	dp[node][1] = 1; // 본인이 얼리어답터인 경우 얼리 개수 1

	for (int i = 0; i < linked[node].size(); i++) {
		int child_node = linked[node][i];
		if (visited[child_node]) continue;
		solve_dfs(child_node);

		dp[node][0] += dp[child_node][1];
		dp[node][1] += min(dp[child_node][1], dp[child_node][0]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	// 연결리스트 구성.
	int u = 0, v = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		linked[u].push_back(v);
		linked[v].push_back(u);
	}

	// 트리의 특성을 이해. <- 순환하는 경로의 트리가 없으며, 모든 정점이 연결이 되어 있으면
	// 시작 노드를 어느 곳으로 잡아도 상관없다. 
	// 루트를 내가 잡기 나름이다. 
	solve_dfs(1);
	cout << min(dp[1][0], dp[1][1]) << "\n";
	return 0;
}