// https://www.acmicpc.net/problem/1325
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n = 0, m = 0, parent = 0, child = 0;

int solve_dfs(int here, vector<vector<int>> & adj_reverse, vector<int> &visited) {
	visited[here] = 1; // 방문처리
	int res = 1;
	for (auto it : adj_reverse[here]) {
		if (visited[it]) continue;
		res += solve_dfs(it, adj_reverse, visited);
	}
	return res;
}

int solve_bfs(int here, vector<vector<int>>& adj_reverse, vector<int>& visited) {
	visited[here] = 1; // 방문처리
	int res = 1;
	queue<int> q;
	q.push(here);
	while(q.size()){
		int there = q.front();
		q.pop();
		for (auto it : adj_reverse[there]) {
			if (visited[it]) continue;
			visited[it] = 1; // 방문처리
			res += 1;
			q.push(it);
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> adj_reverse(n + 1);
	vector<int> visited(n + 1, 0);
	vector<pair<int, int>> idx_distance_vec;
	// 인접행렬 입력 받기
	for (int i = 1; i <= m; i++) {
		cin >> parent >> child;
		adj_reverse[child].push_back(parent);
	}

	// 각 노드별로 dfs를 돌며, 각 노드에서 갈 수 있는 노드의 개수 구하기.
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), 0);	// 초기화
		int node_cnt = solve_bfs(i, adj_reverse, visited);
		if (node_cnt > mx) mx = node_cnt;
		idx_distance_vec.push_back({ i, node_cnt });
	}

	vector<int> result_idx;
	for (pair<int, int> it : idx_distance_vec) {
		if (it.second == mx) result_idx.push_back(it.first);
	}
	sort(result_idx.begin(), result_idx.end());
	for (int it : result_idx) cout << it << " ";

	return 0;
}