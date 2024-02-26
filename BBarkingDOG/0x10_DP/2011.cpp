// https://www.acmicpc.net/problem/2011
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define mod_n 1'000'000
string pswd;
int dp[5004];

bool check_correct() {
	// 잘못된 암호인지 검사
	// (1). 첫 시작이 0이면 안된다.
	// (2). 0이 연속으로 2번 이상 나오면 안된다. + 10, 20 이외의 30,40,50 ...이 있으면 안된다.
	if (pswd[0] == '0') return false; // (1)
	char prev_it = pswd[0];
	int str_len = pswd.length();
	for (int i = 1; i < str_len;i++) {
		if(pswd[i] == '0'){	// (2)
			if (!(prev_it == '1' || prev_it == '2')) {
				return false;
			}
		}
		prev_it = pswd[i];
	}
	return true;
}
int solve_dp() {
	int n = pswd.length();

	// 기저사례
	dp[0] = 1;
	string t_str;
	t_str += pswd[0];
	t_str += pswd[1];
	if (stoi(t_str) <= 26) {					// input : 210  -> res : 1 인 경우 처리.
		if (stoi(t_str) == 10 || stoi(t_str) == 20 || (n >=3 && pswd[2] == '0')) {
			dp[1] = 1;
		}
		else {
			dp[1] = 2;
		}
	}
	else dp[1] = 1;

	// 메모리제이션, 로직 구현
	string prev_ch = string(1, pswd[1]);
	for (int i = 2; i < n; i++) {
		prev_ch += pswd[i];
		if (stoi(prev_ch) <= 26) {												// input : 210  -> res : 1 인 경우 처리.
			if (stoi(prev_ch) < 10 || stoi(prev_ch) == 10 || stoi(prev_ch) == 20 || (i < n-1 && pswd[i+1] == '0')) {
				dp[i] = dp[i - 1] % mod_n;
			}
			else {
				dp[i] = (dp[i - 1] % mod_n + dp[i - 2] % mod_n) % mod_n;
			}
		}
		else {
			dp[i] = dp[i - 1] % mod_n;
		}
		prev_ch.erase(prev_ch.begin());	// 맨 앞 지우기.
	}
	return dp[n-1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> pswd;
	if (check_correct()) cout << solve_dp() << "\n";
	else cout << "0" << "\n";

	return 0;
}

// 수많은 반례
//
// 0 자체는 알파벳으로 변환이 안됩니다.그래서 0앞에 뭐가 오느냐에 따라 경우가 다릅니다.
//
// 0앞에 아무것도 안오는 경우(즉, 맨앞자리가 0인 경우) :
//	05, 035, 017 이런건 0을 어떻게 분할 해도 0이 알파벳으로 변환이 안 되니깐 0이 출력 돼야 합니다
//
//	0 앞에 0이 오는 경우 :
// 0024, 10025, 17200312 같은 경우 00을 어떻게 분할 해도(예 : 10025 -- > 10 0, 1 00, 1 00) 0이 남아서 오류가 납니다.고로 0이 출력돼야 합니다.
//
// 0앞에 1이나 2가 오는 경우 :
// 10, 20 은 알파벳으로 변환이 돼서 경우의 수가 만들어 질 수 있습니다.
//
// 예시 : 20114 -- > 정답: 3 / 1010 -- > 정답: 1 / 111012 -- > 정답: 4
//
// 0앞에 3이나 더 큰 숫자가 오는 경우 :
// 302는 어떻게 분할 해도 30 2, 3 02, 3 0 2 알파벳으로 변환이 안됩니다.고로 0이 출력.
//
// 다른 예시 : 1131212501112122 -- > 정답: 0

//입력: 20236
//답 : 2
//
//입력 : 2727
//답 : 1
//
//입력 : 210
//답 : 1
// 
//입력 : 230
//답 : 0
//
//입력 : 2
//답 : 1
//
//입력 : 0
//답 : 0
//
//입력 : 012
//답 : 0
//
//입력 : 19126
//답 : 6
//
//입력 : 111111111111111111111111111111
//답 : 346269