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

// ���� ������ �� �� ������ ���� ����.
bool solve() {
	int start_cnt = 1;
	int start_idx = 1;
	
	// Ż�� ����. start_cnt ���� ����.
	while (1) {
		if (stk.size()) {
			if (start_cnt > n) {
				if (stk.top() == arr[start_idx]) {
					str_res += "-";	// ���ÿ� �ִ� ���� ������ ���� ä���.
					stk.pop();
					start_idx++; // ������� �ϴ� ������ idx 1���� ��Ű��.
				}
				else {
					make_possible = false; // ������ ���� �� ���� ���.
					break; // Ż��.

					// ���ÿ� ���� ���� �ֱ�.
					stk.push(start_cnt);
					start_cnt++;
					str_res += "+";	// ���ÿ� ���� �ֱ�.
				}
			}
			else {
				if (stk.top() == arr[start_idx]) {
					str_res += "-";	// ���ÿ� �ִ� ���� ������ ���� ä���.
					stk.pop();
					start_idx++; // ������� �ϴ� ������ idx 1���� ��Ű��.
				}
				else {
					// ���ÿ� ���� ���� �ֱ�.
					stk.push(start_cnt);
					start_cnt++;
					str_res += "+";	// ���ÿ� ���� �ֱ�.
				}
			}
		}
		else {
			if (start_cnt > n) break; // Ż�� ����.

			stk.push(start_cnt);
			start_cnt++;
			str_res += "+";	// ���ÿ� ���� �ֱ�.
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