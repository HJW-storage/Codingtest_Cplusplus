// https://www.acmicpc.net/problem/2504
// 분배법칙을 적절히 활용해야 하는 문제!!

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> stk;
stack<char> stk2; // 더하는 기준을 세우는 stack.

string gaulho = "";

void Clear_Stack(stack<char> &stk2) {
	stack<char> empty;
	swap(stk2, empty);
	return;
}

int solve() {
	int res = 0;
	int _tmp = 1;

	for (int i = 0; i < gaulho.size(); i++) {
		if (gaulho[i] == '(') {
			_tmp *= 2;
			stk.push(gaulho[i]);
			Clear_Stack(stk2); // 여는 괄호시, stk2 비우기.
		}
		else if (gaulho[i] == ')') {
			if (stk.size() && stk.top() == '(') stk.pop();
			else stk.push(gaulho[i]);

			// 결과값에 더할지에 대한 예외처리
			if (stk2.size() == 0) {
				res += _tmp;
				stk2.push(gaulho[i]);
			}
			else {
				stk2.push(gaulho[i]);
			}

			_tmp /= 2;
		}
		else if (gaulho[i] == '[') {
			_tmp *= 3;
			stk.push(gaulho[i]);
			Clear_Stack(stk2); // 여는 괄호시, stk2 비우기.
		}
		else if (gaulho[i] == ']') {
			if (stk.size() && stk.top() == '[') stk.pop();
			else stk.push(gaulho[i]);

			// 결과값에 더할지에 대한 예외처리
			if (stk2.size() == 0) {
				res += _tmp;
				stk2.push(gaulho[i]);
			}
			else {
				stk2.push(gaulho[i]);
			}

			_tmp /= 3;
		}
	}

	// 만약 stack이 비어있지 않으면, 해당 입력은 잘못된 입력이다.
	if (stk.size()) res = 0;
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> gaulho;
	cout << solve() << "\n";

	return 0;
}