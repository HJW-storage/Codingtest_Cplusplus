// https://www.acmicpc.net/problem/2870
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int n;
vector<string> v_num;

void zero_rule(string &num_str) {
	if (num_str.size() != 0) {
		while (true) {
			if (num_str.size() != 0 && *(num_str.begin()) == '0') {
				num_str.erase(num_str.begin());
			}
			else {
				break;
			}
		}
		if (num_str.size() == 0) num_str = "0";
		v_num.push_back(num_str);
	}
}

bool cmp(string& a, string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string gulza = "";
		cin >> gulza;

		string num_str = "";
		for (char it : gulza) {
			if (it >= 48 && it <= 57) {
				num_str += it;
			}
			else {
				zero_rule(num_str);
				num_str = ""; // 초기화
			}
		}
		// 마지막 string 문자가 숫자로 끝나는 경우 출력하는 구문 추가로 필요.
		if (num_str.size() != 0) {
			zero_rule(num_str);
			num_str = ""; // 초기화
		}
	}
	sort(v_num.begin(), v_num.end(), cmp);
	for (auto& it : v_num) cout << it << "\n";

	return 0;
}