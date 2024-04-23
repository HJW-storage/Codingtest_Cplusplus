// https://softeer.ai/practice/7703

#include <iostream>
#include <algorithm>

using namespace std;

// '0' : 48
// 'A' : 65
// 'a' : 97
// 'z' : 122 

int n = 0;
string S_str = "", T_str = "", res_str = "";

int search_X() {
	int idx_X = 0;
	int size = S_str.length();

	for (int i = 0; i < size;i++){
		if (S_str[i] == 'x' || S_str[i] == 'X') {
			idx_X = i;
			break;
		}
	}
	return idx_X;
}

char extract_idx(int &t_idx) {
	char tmp;

	// 소문자인 경우 대문자로 바꾸기. 
	if (97 <= T_str[t_idx] && T_str[t_idx] <= 122) {
		tmp = T_str[t_idx] - 32;
	}
	else {
		tmp = T_str[t_idx];
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		S_str = "", T_str = "";
		cin >> S_str >> T_str;

		int idx = search_X();
		res_str += extract_idx(idx);
	}

	cout << res_str << "\n";
	return 0;
}