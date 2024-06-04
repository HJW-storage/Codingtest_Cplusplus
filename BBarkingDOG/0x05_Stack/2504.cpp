// https://www.acmicpc.net/problem/2504
// �й��Ģ�� ������ Ȱ���ؾ� �ϴ� ����!!

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> stk;
stack<char> stk2; // ���ϴ� ������ ����� stack.

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
			Clear_Stack(stk2); // ���� ��ȣ��, stk2 ����.
		}
		else if (gaulho[i] == ')') {
			if (stk.size() && stk.top() == '(') stk.pop();
			else stk.push(gaulho[i]);

			// ������� �������� ���� ����ó��
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
			Clear_Stack(stk2); // ���� ��ȣ��, stk2 ����.
		}
		else if (gaulho[i] == ']') {
			if (stk.size() && stk.top() == '[') stk.pop();
			else stk.push(gaulho[i]);

			// ������� �������� ���� ����ó��
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

	// ���� stack�� ������� ������, �ش� �Է��� �߸��� �Է��̴�.
	if (stk.size()) res = 0;
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> gaulho;
	cout << solve() << "\n";

	return 0;
}