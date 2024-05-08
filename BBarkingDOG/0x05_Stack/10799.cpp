// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string steel_stick = "";
stack<char> stk;

int solve() {
	int str_len = steel_stick.length();

	int res = 0;
	for (int i = 0; i < str_len; i++) {
		// �������� ��ġ. ���� ������ ����� res�� �����ش�.
		if (i < str_len - 1) {
			if (steel_stick[i] == '(' && steel_stick[i + 1] == ')') {
				i++; // �ε��� �ϳ� �����ֱ�.
				res += stk.size();
			}
			// ����� ���� �κ�. �ش� ����� �����̹Ƿ� res�� 1�� �����ְ�, pop�Ѵ�.
			// (stk.top() == '(' && steel_stick[i] == ')') �̷��� ���Ÿ� stk.size() �˻��ϴ� �͵� �߰����־�� �Ѵ�.
			// (steel_stick[i] == ')' && stk.top() == '(') �� A and B��  A�� ���� ����, B�� �����Ѵ�.
			else if (steel_stick[i] == ')' && stk.top() == '(') {
				res += 1;
				stk.pop();
			}
			// �� �̿�, stack�� push.
			else {
				stk.push(steel_stick[i]);
			}
		}
		else if(i == str_len - 1){
			if (steel_stick[i] == ')' && stk.top() == '(') {
				res += 1;
				stk.pop();
			}
		}
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> steel_stick;

	cout << solve() << "\n";

	return 0;
}