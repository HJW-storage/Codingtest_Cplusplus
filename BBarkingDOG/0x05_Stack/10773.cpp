// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int k = 0;
stack<int> stk;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> k;
	int _tmp = 0;
	for (int i = 0; i < k; i++) {
		cin >> _tmp;
		if (_tmp == 0) stk.pop(); // 가장 최근에 쓴 수 지우기.
		else stk.push(_tmp);
	}

	// 점수 계산.
	int res = 0;
	while (stk.size()) {
		res += stk.top();
		stk.pop();
	}
	
	cout << res << "\n";
	return 0;
}