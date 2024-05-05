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
		if (_tmp == 0) stk.pop(); // ���� �ֱٿ� �� �� �����.
		else stk.push(_tmp);
	}

	// ���� ���.
	int res = 0;
	while (stk.size()) {
		res += stk.top();
		stk.pop();
	}
	
	cout << res << "\n";
	return 0;
}