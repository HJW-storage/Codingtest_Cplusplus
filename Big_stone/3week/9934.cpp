// https://www.acmicpc.net/problem/9934

// 1. 방문처리
// 2. 완전 탐색
// 3. 큐

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int k = 0, node_n = 0;
queue<int> node_q, tmp_q;
int visited[1050];	// 최대 k = 10일 때, 2^10 = 1024 
int node_arr[1050];
vector<int> res[11];

int multi_n(int a, int b) {
	int tmp_m = 1;
	for (int i = 1; i <= b; i++) {
		tmp_m *= a;
	}
	return tmp_m;
}
void Qclear(queue<int> &q) {
	queue<int> empty;
	swap(q, empty);
}
void solve(int start_idx) {
	int step = start_idx;
	int depth = 2;

	while(depth != k+1){
		step = step - step / 2;

		while (node_q.size()) {
			int cur_idx = node_q.front();
			//cout << "cur_idx : " << cur_idx << "\n";
			node_q.pop();

			int next_idx_left = cur_idx - step;
			int next_idx_right = cur_idx + step;
			for (int it : {next_idx_left, next_idx_right}) {
				if (it >= 0 && it < node_n) {
					if (visited[it] == 0) {
						visited[it] = 1; // 방문처리
						res[depth].push_back(node_arr[it]);	// 트리 구성. 
						tmp_q.push(it);
					}
				}
			}

			// 2가지 경우를 for문으로 하나로 간략히 쓰면 위쪽과 같다. 
			//if (next_idx_left >= 0 && next_idx_left < node_n) {
			//	if (visited[next_idx_left] == 0) {
			//		visited[next_idx_left] = 1; // 방문처리
			//		res[depth].push_back(node_arr[next_idx_left]);	// 트리 구성. 
			//		//cout << node_arr[next_idx_left] << " 추가_left\n";
			//		tmp_q.push(next_idx_left);
			//	}
			//}
			//if (next_idx_right >= 0 && next_idx_right < node_n) {
			//	if (visited[next_idx_right] == 0) {
			//		visited[next_idx_right] = 1; // 방문처리
			//		res[depth].push_back(node_arr[next_idx_right]);	// 트리 구성. 
			//		//cout << node_arr[next_idx_right] << " 추가_right\n";
			//		tmp_q.push(next_idx_right);
			//	}
			//}
		}
		node_q = tmp_q;
		Qclear(tmp_q); // tmp_q 초기화. 
		depth++;
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	node_n = multi_n(2, k) - 1;
	//cout << "node_n : " << node_n << "\n";
	for (int i = 0; i < node_n; i++) {
		cin >> node_arr[i];
	}
	
	int start = node_n / 2;	// 루트 노드 시작.
	node_q.push(start);
	visited[start] = 1; // 시작 루트 노드 방문처리
	res[1].push_back(node_arr[start]);	// 트리 구성. 

	solve(start);

	for (int i = 1; i <= k; i++) {
		for (int it : res[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}