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
		// 레이저가 위치. 현재 스택의 사이즈를 res에 더해준다.
		if (i < str_len - 1) {
			if (steel_stick[i] == '(' && steel_stick[i + 1] == ')') {
				i++; // 인덱스 하나 더해주기.
				res += stk.size();
			}
			// 막대기 종단 부분. 해당 막대기 종료이므로 res에 1을 더해주고, pop한다.
			// (stk.top() == '(' && steel_stick[i] == ')') 이렇게 쓸거면 stk.size() 검사하는 것도 추가해주어야 한다.
			// (steel_stick[i] == ')' && stk.top() == '(') 은 A and B는  A가 참일 때만, B를 실행한다.
			else if (steel_stick[i] == ')' && stk.top() == '(') {
				res += 1;
				stk.pop();
			}
			// 그 이외, stack에 push.
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