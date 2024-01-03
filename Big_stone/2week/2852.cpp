// https://www.acmicpc.net/problem/2852
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int score[3] = { -1, 0, 0 };
	int n = 0;
	cin >> n;

	string a_wint = "", a_wint_start = "", b_wint = "", b_wint_start = "";
	string same_time = "";

	int a_min = 0, a_sec = 0, b_min = 0, b_sec = 0, same_min = 0, same_sec = 0;
	int a_winmin = 0, a_winsec = 0, b_winmin = 0, b_winsec = 0;
	int a_winmin_res = 0, a_winsec_res = 0, b_winmin_res = 0, b_winsec_res = 0;
	int team_n = 0;
	string time = "";

	int a_win_flag = 1, b_win_flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> team_n >> time;
		score[team_n]++;

		if (score[1] > score[2] && a_win_flag == 1) {
			a_win_flag++;
			a_wint_start = time;	// a팀 이기기 시작한 시간 기록.

			string min_temp = a_wint_start.substr(0, 2);
			a_min = atoi(min_temp.c_str());
			string sec_temp = a_wint_start.substr(3, 2);
			a_sec = atoi(sec_temp.c_str());
		}
		else if (score[1] < score[2] && b_win_flag == 1) {
			b_win_flag++;
			b_wint_start = time;	// b팀 이기기 시작한 시간 기록.

			string min_temp = b_wint_start.substr(0, 2);
			b_min = atoi(min_temp.c_str());
			string sec_temp = b_wint_start.substr(3, 2);
			b_sec = atoi(sec_temp.c_str());
		}
		else if (score[1] == score[2] && score[1] != 0 && score[2] != 0) {
			a_win_flag = 1;
			b_win_flag = 1;
			same_time = time;	// 동점인 시간 기록. 

			string min_temp = same_time.substr(0, 2);
			same_min = atoi(min_temp.c_str());
			string sec_temp = same_time.substr(3, 2);
			same_sec = atoi(sec_temp.c_str());

			// a 또는 b 팀의 이기고 있던 시간을 구해서 기록.
			if (a_wint_start.size() != 0) {
				a_winmin = same_min - a_min ;
				a_winsec = same_sec - a_sec;
				if (a_winsec < 0) {
					a_winsec += 60;
					a_winmin -= 1;
				}

				a_winmin_res += a_winmin;
				a_winsec_res += a_winsec;
				if (a_winsec_res >= 60) {
					a_winsec_res -= 60;
					a_winmin_res++;
				}

				a_wint_start = ""; // 초기화
			}
			else if (b_wint_start.size() != 0) {
				b_winmin = same_min- b_min;
				b_winsec = same_sec - b_sec;
				if (b_winsec < 0) {
					b_winsec += 60;
					b_winmin -= 1;
				}

				b_winmin_res += b_winmin;
				b_winsec_res += b_winsec;
				if (b_winsec_res >= 60) {
					b_winsec_res -= 60;
					b_winmin_res++;
				}

				b_wint_start = ""; // 초기화
			}
		}
	}

	// for문 탈출하고 마지막 계산 과정 있어야 한다.
	if (a_wint_start.size() != 0) {
		a_winmin = 48 - a_min;
		a_winsec = 0 - a_sec;
		if (a_winsec < 0) {
			a_winsec += 60;
			a_winmin -= 1;
		}

		a_winmin_res += a_winmin;
		a_winsec_res += a_winsec;
		if (a_winsec_res >= 60) {
			a_winsec_res -= 60;
			a_winmin_res++;
		}
	}
	else if (b_wint_start.size() != 0) {
		b_winmin = 48 - b_min;
		b_winsec = 0 - b_sec;
		if (b_winsec < 0) {
			b_winsec += 60;
			b_winmin -= 1;
		}

		b_winmin_res += b_winmin;
		b_winsec_res += b_winsec;
		if (b_winsec_res >= 60) {
			b_winsec_res -= 60;
			b_winmin_res++;
		}
	}

	string res_a_min = "", res_a_sec = "", res_b_min = "",  res_b_sec = "";

	if (a_winmin_res < 10) res_a_min = "0" + to_string(a_winmin_res);
	else res_a_min = to_string(a_winmin_res);
	if (a_winsec_res < 10) res_a_sec = "0" + to_string(a_winsec_res);
	else res_a_sec = to_string(a_winsec_res);

	
	if (b_winmin_res < 10) res_b_min = "0" + to_string(b_winmin_res);
	else res_b_min = to_string(b_winmin_res);
	if (b_winsec_res < 10) res_b_sec = "0" + to_string(b_winsec_res);
	else res_b_sec = to_string(b_winsec_res);

	string res_a = res_a_min + ":" + res_a_sec;
	string res_b = res_b_min + ":" + res_b_sec;

	cout << res_a << "\n";
	cout << res_b << "\n";

	return 0;
}