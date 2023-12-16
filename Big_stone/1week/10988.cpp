//https://www.acmicpc.net/problem/10988

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string alphabet_str = "";

int main() {
	cin >> alphabet_str;

	// 그냥 단순히 temp_str = alphabet_str; 로 해도된다.
	// 깊은 복사할 때, temp_str로 복사해야할 때, 길이가 맞아야 한다. 
	string temp_str;
	for (char it : alphabet_str) {
		temp_str.push_back(it);
	}

	// 깊은 복사
	copy(alphabet_str.begin(), alphabet_str.end(), temp_str.begin());

	// 복사한거 뒤집기
	reverse(temp_str.begin(), temp_str.end());

	// 검사
	if (alphabet_str == temp_str) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}