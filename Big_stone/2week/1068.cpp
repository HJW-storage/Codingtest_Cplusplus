// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, delete_num;

void solve_leafnode(vector<vector<int>> &vec, int delete_num) {
	if (vec[delete_num].size() == 0) {
		vec[delete_num].push_back(1004); // 리프 노드 삭제의 의미로 자식노드를 추가해주는 방법을 사용한다.
		// 이후 검사지 vector 크기가 0인 것을 자식노드 개수로 세면된다.
		return;
	}
	else {
		for (auto it : vec[delete_num]) {
			solve_leafnode(vec, it);
		}
	}
	return;
}
int main() {
	cin >> n;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; i++) {
		int in_tmp;
		cin >> in_tmp;
		if (in_tmp == -1) continue;
		vec[in_tmp].push_back(i);
	}

	cin >> delete_num;
	solve_leafnode(vec, delete_num);

	// 예외 케이스 처리하기 위해 추가함
	// 입력이  
	// 5
	// -1 0 1 2 3
	// 2 
	// 로 주어지면 정답은 : 1 이다. 아래 부분이 없으면 출력 : 0 이었다.
	// 위쪽 예시를 그림으로 쉽게 표현하면 아래처럼 일자로된 트리이다.
	// [0]
	//  |
	// [1]
	//  |
	// [2]
	//  |
	// [3]
	//  |
	// [4]
	for (int i = 0; i < n; i++) {
		for (auto it : vec[i]) {
			// 무턱대고 pop_back을 해도 되는 이유는 위쪽 solve_leafnode에서 이미 처리가 다끝난 뒤에,
			// pop_back을 하면 vec[i]가 여러개인 경우 하나가 pop되도 답에 영향을 주지 않음. 
			// 단, vec[i]가 1개 일 때, 해당 리프노드 지운것을 pop 해주면 해당 left노드는 비어 있는 노드가 되면 
			// leaf 노드가 되기때문에 해당 조건문을 추가해줬다. 
			if (it == delete_num) {
				vec[i].pop_back();
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (vec[i].size() == 0) res++;
	}
	cout << res << "\n";
	return 0;
}