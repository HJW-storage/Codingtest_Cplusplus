// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string in_str, explosion_str, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> in_str;
	cin >> explosion_str;

	int in_len = in_str.length();
	int exp_len = explosion_str.length();
	
	// res 결과 문자열에 입력 문자열을 하나씩 더한다.
	// 문자열의 길이가 폭발 문자열 길이 이상일 때, 끝부분에 폭발 문자열이 있는지 검사한다.
	// 폭발 문자열이 있으면 erase 함수를 활용해서 지운다.
	for (int i = 0; i < in_len; i++) {
		res += in_str[i];
		int res_len = res.length();
		int tmp_len = exp_len;
		bool erase_flag = true;
		// 폭발 문자열이 있는지 검사하고, 있다면 지우는 로직.
		if (res_len >= exp_len) {
			for (int j = 1; j <= exp_len; j++) {
				res_len--;
				tmp_len--;
				if (res[res_len] == explosion_str[tmp_len]) continue;
				erase_flag = false;
				break;
			}
			if (erase_flag) {
				res.erase(res.length() - exp_len, exp_len);
			}
		}
	}

	// str.substr() 함수를 사용하면 위 코드를 간략하게 줄일 수 있다.
	/*for (int i = 0; i < in_len; i++) {
		res += in_str[i];
		int res_len = res.length();
		if (res_len >= exp_len) {
			if (res.substr(res_len - exp_len, exp_len) == explosion_str) {
				res.erase(res_len - exp_len, exp_len);
			}
		}
	}*/

	if (res == "") cout << "FRULA" << "\n";
	else cout << res << "\n";

	// find, erase 함수는 시간초과이다.
	//// 로직구현 
	//while (in_str.find(explosion_str) != string::npos) {
	//	int start = in_str.find(explosion_str);
	//	in_str.erase(start, exp_len);
	//}
	//if (in_str == "") cout << "FRULA" << "\n";
	//else cout << in_str << "\n";

	return 0;
}