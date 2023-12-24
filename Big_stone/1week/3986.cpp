// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, result = 0;
	string ab_word;

	cin >> n; 

	//v_word.push_back('abc');
	//cout << v_word.empty() << endl; // 비어 있다면 1을 출력, 아니면 0을 출력.
	//cout << *(v_word.end() - 1) << endl;

	for (int i = 0; i < n; i++) {
		vector<char> v_word;
		cin >> ab_word;
		// stack을 이용하여 쌍을 맞추는 것.
		// stack이 비어있거나 현재 값이 stack의 최상단 값과 같다면 
		// 최상단 값을 빼고 pop_back()
		// 다른 경우는 스택에 다시 넣는다 push_back()
		for (char it : ab_word) {
			if ( (v_word.empty()) || (it != *(v_word.end() - 1)) ) {
				v_word.push_back(it);
			}
			else {
				v_word.pop_back();
			}
		}

		if (v_word.empty()) {
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}