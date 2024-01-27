// https://www.acmicpc.net/problem/2577

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int a, b, c, res;	// 결과값 최대 10억이므로 int형으로 표현 가능.
int alphabet_arr[10];

void solve(int res) {
	string res_str = to_string(res);	// int형 -> string으로 변환
	for (char it : res_str) {
		alphabet_arr[it - '0']++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	cin >> b;
	cin >> c;
	res = a * b * c;
	solve(res);

	for (int i = 0; i < 10; i++) {
		cout << alphabet_arr[i] << "\n";
	}
	return 0;
}
