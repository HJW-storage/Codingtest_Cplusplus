// https://www.acmicpc.net/problem/3986
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, res = 0;
	cin >> n;

	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		stack<char> stk_word;
		for (char it : word) {
			if (stk_word.size() && stk_word.top() == it) {
				stk_word.pop();
			}
			else {
				stk_word.push(it);
			}
		}

		if (stk_word.size() == 0) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}