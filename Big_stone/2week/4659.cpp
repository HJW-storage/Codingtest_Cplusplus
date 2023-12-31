#pragma warning(disable 4996)
// https://www.acmicpc.net/problem/4659

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//char moum[5] = { 'a', 'e', 'i', 'o', 'u' };
//char zaum[21] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
string moum_str = "aeiou";
string zaum_str = "bcdfghjklmnpqrstvwxyz";

bool test_password(string& pd) {
	// 규칙 1 검사
	if (pd.find(moum_str[0]) == string::npos && pd.find(moum_str[1]) == string::npos && pd.find(moum_str[2]) == string::npos
		&& pd.find(moum_str[3]) == string::npos && pd.find(moum_str[4]) == string::npos) {
		return false;
	}

	// 규칙 2 검사
	int moum_cnt = 0, zaum_cnt = 0;
	for (char it : pd) {
		if (moum_str.find(it) != string::npos) {
			moum_cnt++;
			zaum_cnt = 0;
		}
		else {
			moum_cnt = 0;
			zaum_cnt++;
		}

		if (moum_cnt == 3 || zaum_cnt == 3) {
			return false;
		}
	}

	// 규칙 3 검사
	char prev_ch = ' ';
	for (char it : pd) {
		char cur_ch = it;
		if (prev_ch == cur_ch) {
			if (prev_ch == 'e' && cur_ch == 'e') { continue;}
			else if (prev_ch == 'o' && cur_ch == 'o') { continue;}
			else {
				return false;
			}
		}
		prev_ch = cur_ch;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string password;
	while (true) {
		cin >> password;
		if (password == "end") {
			break;
		}

		bool result = test_password(password);
		if (result) {
			cout << "<" << password << "> is acceptable." << "\n";
		}
		else {
			cout << "<" << password << "> is not acceptable." << "\n";
		}

	}

	return 0;
}