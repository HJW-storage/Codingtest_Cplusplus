// https://www.acmicpc.net/problem/2870
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 처음에 int로 처리했는데, 문제를 살펴보니 100문자 이내인데 숫자가 100자리이면 무조건 오버플로우 발생이다.
// string으로 처리해야한다.
vector<string> v_num;
string number_1to9 = "123456789";
int n = 0;

void zero_rule(string &num_str, bool zero_flag) {
	if (num_str.size() != 0) {
		int pos, min_pos = 1004;
		for (char ch : number_1to9) {
			if ((pos = num_str.find(ch)) != string::npos) {
				zero_flag = false; // 0으로만 이루어진게 아니다.
				min_pos = min(min_pos, pos); // 0이외의 숫자가 시작하는 첫 인덱스 구하기.
			}
		}

		if (zero_flag == false) {
			num_str.erase(0, min_pos);
		}
		else {
			num_str = "0";	// 0 여러개를 0 1개로 초기화.
		}
		v_num.push_back(num_str);
	}
}
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string gulza = "";
	for (int i = 0; i < n; i++) {
		cin >> gulza;
		string num_str = "";
		int gulza_size = gulza.size();
		int gulza_length = 0;
		bool zero_flag = true;

		for (char it : gulza) {
			gulza_length++;
	
			if (int(it) >= int('0') && int(it) <= int('9')) {
				num_str += it;
				zero_flag = true;
			}
			else {
				zero_rule(num_str, zero_flag);
				num_str = "";	// 초기화
			}

			// 마지막이 숫자 인 경우에는 vec에 push 해준다. (it == *(gulza.end() - 1)) <- 이렇게만 쓰면 마지막 이전과 마지막이 33 이렇게 끝나는 경우 중복으로 추가된다.
			// 그렇기에 길이도 같이 비교한다. (gulza_length == gulza_size) string의 마지막인지 길이를 통해 확인.
			// 빈 문자열 추가시키면 빈 문자열도 추가되게 된다. 따라서, 빈 문자열이 아닌 경우도 검사한다. (num_str.size() != 0)
			if (gulza_length == gulza_size && it == *(gulza.end() - 1) && num_str.size() != 0) {
				zero_rule(num_str, zero_flag);
			}
		}
	}

	sort(v_num.begin(), v_num.end(), cmp);
	for (auto& it : v_num) { cout << it << "\n";}

	return 0;
}

// ---------------------------------------------------------- 함수화 안시키고 쭉 작성항 코드 -------------------------------------------------------------
//// https://www.acmicpc.net/problem/2870
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int n = 0;
//
//// 처음에 int로 처리했는데, 문제를 살펴보니 100문자 이내인데 숫자가 100자리이면 무조건 오버플로우 발생이다.
//// string으로 처리해야한다.
//vector<string> v_num;
//string number_1to9 = "123456789";
//
//bool cmp(const string& a, const string& b) {
//	if (a.size() == b.size()) return a < b;
//	return a.size() < b.size();
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	string gulza = "";
//	for (int i = 0; i < n; i++) {
//		cin >> gulza;
//		string num_str = "";
//		int gulza_size = gulza.size();
//		int gulza_length = 0;
//		bool zero_flag = true;
//
//		for (char it : gulza) {
//			gulza_length++;
//			
//			if (int(it) >= int('0') && int(it) <= int('9')) {
//				num_str += it;
//				zero_flag = true;
//			}
//			else {
//				if (num_str.size() != 0) {
//					int pos, min_pos = 1004;
//					for (char ch : number_1to9) {
//						if ( (pos = num_str.find(ch)) != string::npos) {
//							zero_flag = false; // 0으로만 이루어진게 아니다.
//							min_pos = min(min_pos, pos); // 0이외의 숫자가 시작하는 첫 인덱스 구하기.
//						}
//					}
//
//					if (zero_flag == false) {
//						num_str.erase(0, min_pos);
//					}
//					else {
//						num_str = "0";	// 0 여러개를 0 1개로 초기화.
//					}
//					v_num.push_back(num_str);
//				}
//				num_str = "";	// 초기화
//			}
//
//			// 마지막이 숫자 인 경우에는 vec에 push 해준다. (it == *(gulza.end() - 1)) <- 이렇게만 쓰면 마지막 이전과 마지막이 33 이렇게 끝나는 경우 중복으로 추가된다.
//			// 그렇기에 길이도 같이 비교한다. (gulza_length == gulza_size) string의 마지막인지 길이를 통해 확인.
//			// 빈 문자열 추가시키면 빈 문자열도 추가되게 된다. 따라서, 빈 문자열이 아닌 경우도 검사한다. (num_str.size() != 0)
//			if (gulza_length == gulza_size && it == *(gulza.end() - 1) && num_str.size() != 0) {
//				if (num_str.size() != 0) {
//					int pos, min_pos = 1004;
//					for (char ch : number_1to9) {
//						if ((pos = num_str.find(ch)) != string::npos) {
//							zero_flag = false; // 0으로만 이루어진게 아니다.
//							min_pos = min(min_pos, pos); // 0이외의 숫자가 시작하는 첫 인덱스 구하기.
//						}
//					}
//
//					if (zero_flag == false) {
//						num_str.erase(0, min_pos);
//					}
//					else {
//						num_str = "0";	// 0 여러개를 0 1개로 초기화.
//					}
//					v_num.push_back(num_str);
//				}
//			}
//		}
//	}
//
//	sort(v_num.begin(), v_num.end(), cmp);
//
//	for (auto& it : v_num) {
//		cout << it << "\n";
//	}
//
//	return 0;
//}