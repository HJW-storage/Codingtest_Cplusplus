#include <iostream>
#include <algorithm>

using namespace std;

bool isMoum(int idx) {
	return idx == 'e' || idx == 'a' || idx == 'i' || idx == 'o' || idx == 'u';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string password = "";
	while (true) {
		cin >> password;
		if (password == "end") break;

		bool res_flag = true;

		int moum_cnt = 0, zaum_cnt = 0;
		bool moum_flag = false;
		int prev_idx = ' ';
		for (int i = 0; i < password.size(); i++) {
			int idx = password[i]; // 각 문자의 아스키 코드 값이 idx에 저장된다.
			if (isMoum(idx)) {
				moum_cnt++;
				zaum_cnt = 0;
				moum_flag = true;
			}
			else {
				moum_cnt = 0;
				zaum_cnt++;
			}
			if (moum_cnt == 3 || zaum_cnt == 3) {
				res_flag = false;
				break;
			}

			if (prev_idx == idx && idx != 'e' && idx != 'o') {
				res_flag = false;
				break;
			}
			prev_idx = idx;
		}

		if (res_flag == true && moum_flag == true) {
			cout << "<" << password << "> is acceptable." << "\n";
		}
		else {
			cout << "<" << password << "> is not acceptable." << "\n";
		}
	}

	return 0;
}