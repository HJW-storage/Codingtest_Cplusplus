// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define max_n 100004

int n = 0, arr[max_n] = { 0, };
stack<int> stk;
bool make_possible = true;
string str_res = "";

// 같은 정수가 두 번 나오는 일은 없다.
bool solve() {
	int start_cnt = 1;
	int start_idx = 1;
	
	// 탈출 조건. start_cnt 숫자 기준.
	while (1) {
		if (stk.size()) {
			if (start_cnt > n) {
				if (stk.top() == arr[start_idx]) {
					str_res += "-";	// 스택에 있는 숫자 빼내서 수열 채우기.
					stk.pop();
					start_idx++; // 만들고자 하는 수열의 idx 1증가 시키기.
				}
				else {
					make_possible = false; // 수열을 만들 수 없는 경우.
					break; // 탈출.

					// 스택에 다음 숫자 넣기.
					stk.push(start_cnt);
					start_cnt++;
					str_res += "+";	// 스택에 숫자 넣기.
				}
			}
			else {
				if (stk.top() == arr[start_idx]) {
					str_res += "-";	// 스택에 있는 숫자 빼내서 수열 채우기.
					stk.pop();
					start_idx++; // 만들고자 하는 수열의 idx 1증가 시키기.
				}
				else {
					// 스택에 다음 숫자 넣기.
					stk.push(start_cnt);
					start_cnt++;
					str_res += "+";	// 스택에 숫자 넣기.
				}
			}
		}
		else {
			if (start_cnt > n) break; // 탈출 조건.

			stk.push(start_cnt);
			start_cnt++;
			str_res += "+";	// 스택에 숫자 넣기.
		}
	}
	return make_possible;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (solve()) {
		for (char it : str_res) cout << it << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}

/*
TC-1
<input>  
5
1
2
3
4
5
<output>
+
-
+
-
+
-
+
-
+
-

TC-2
<input>
5
5
4
3
2
1
<output>
+
+
+
+
+
-
-
-
-
-
*/