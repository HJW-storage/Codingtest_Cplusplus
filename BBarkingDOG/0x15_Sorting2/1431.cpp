// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, string> P;

int n = 0;
string str_arr[54];
vector<P> vec; // {길이, 문자열}

int cal_strnum(string& tmp_str) {
	int _num = 0;
	for (char it : tmp_str) {
		if ('0' <= it && it <= '9') _num += (it - '0');
	}
	return _num;
}

bool comp_str(string& str_a, string& str_b, int len) {
	bool flag = true;
	// str_a, str_b 가 길이가 같을 때 들어오는 함수이다.
	for (int i = 0; i < len; i++) {
		if (str_a[i] == str_b[i]) continue;
		if (str_a[i] < str_b[i]) {
			flag = true;
			break;
		}
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

bool cmp(P& a, P& b) {
	if (a.first == b.first) {
		int a_sum = cal_strnum(a.second);
		int b_sum = cal_strnum(b.second);
		if (a_sum == b_sum) {
			return comp_str(a.second, b.second, a.second.length());
		}
		return a_sum < b_sum;
	}

	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	string _tmp = "";

	for (int i = 0; i < n; i++) {
		cin >> _tmp;
		vec.push_back(make_pair(_tmp.length(), _tmp));
	}

	sort(vec.begin(), vec.end(), cmp);

	for (P& it : vec) {
		cout << it.second << "\n";
	}
	return 0;
}