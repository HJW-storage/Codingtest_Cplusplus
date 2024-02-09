// https://www.acmicpc.net/problem/9935

// stack을 활용한 풀이. 
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
string in_str, explosion_str;
stack<char> stk;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> in_str;
	cin >> explosion_str;

	int in_len = in_str.length();
	int exp_len = explosion_str.length();

	// stack을 활용
	// stack의 top이 폭발 문자열의 끝 문자랑 같다면 폭발 문자열 길이 만큼 stack에서 빼서 비교하고
	// 맞다면 제거하고 아니라면 다시 stack에 넣어준다.
	// (주의) 스텍은 LIFO 구조이기에 reverse 함수를 적절히 활용해 줘야한다.
	for (int i = 0; i < in_len; i++) {
		stk.push(in_str[i]);
		if (stk.size() >= exp_len && stk.top() == explosion_str[exp_len - 1]) {
			// 폭발 문자열과 같은지 검사하기
			string tmp_str = "";
			for (int j = 1; j <= exp_len; j++) {
				tmp_str += stk.top();
				stk.pop();
			}
			// 스택에서 뺀 것이므로 순서가 뒤집혀 있기에 reverse로 다시 뒤집어분다.
			reverse(tmp_str.begin(), tmp_str.end());
			if (tmp_str == explosion_str) { ; }
			else {
				// 폭발 문자열이 아니기에 스택에서 빼온 문자열 다시 넣어준다.
				for (char it : tmp_str) {
					stk.push(it);
				}
			}
		}
	}

	if (stk.size() == 0) cout << "FRULA";
	else {
		string res = "";
		while (stk.size()) {
			res += stk.top();
			stk.pop();
		}
		// 스택에서 뺀 것이므로 순서가 뒤집혀 있기에 reverse로 다시 뒤집어분다.
		reverse(res.begin(), res.end());
		cout << res << "\n";
	}
	return 0;
}