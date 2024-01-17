// https://www.acmicpc.net/problem/16637
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0, res = -987654321;
string susik;
vector<char> oper_v;
vector<int> num_v;

int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}
void go(int here, int num_sum) {
	// 기저 사례
	if (here == num_v.size() - 1) {
		res = max(res, num_sum);
		return;
	}

	go(here + 1, oper(oper_v[here], num_sum, num_v[here + 1]));
	if(here + 2 <= num_v.size() - 1){
		go(here + 2, oper(oper_v[here], num_sum, oper(oper_v[here+1], num_v[here+1], num_v[here + 2])));
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	// 입력되는 n은 홀수 이다. 
	cin >> susik;
	for (int i = 0; i < n; i++) {
		if (susik[i] == '+' || susik[i] == '-' || susik[i] == '*') {
			oper_v.push_back(susik[i]);
		}
		else {
			num_v.push_back(susik[i] - '0');
		}
	}
	go(0, num_v[0]);
	cout << res << "\n";

	return 0;
}