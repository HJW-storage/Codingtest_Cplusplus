// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, delete_node, root, temp;
vector<int> adj[54]; // 54개의 벡터를 원소로 갖는 배열을 선언

// 인접행렬, 트리는 root 노드부터 탐색하는게 쉽다.
int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == delete_node) continue;
		ret += dfs(there);
		child++; // there로 이동한 것은 자식 노드가 있다는 의미이므로 ++ 해준다.
	}
	if (child == 0) return 1; // 위쪽 for문을 진입하지 못한 것은 해당 노드 자체가 자식노드라는 의미이므로 return 1 해주자.
	// 결과적으로 깊이 탐색 후, 가장 깊이 있는 자식노드의 개수만 1이 반환되는 것이다.
	return ret;	// 최종 결과 반환.
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	cin >> delete_node;

	// 위쪽에 정의한 dfs는 root일때는 정확한 답을 출력하지 않는다.
	// 따라서, 예외처리르 해준 것이다. 
	if (delete_node == root) {
		cout << "0" << "\n";
		return 0;
	}
	else {
		cout << dfs(root) << "\n";
	}
}