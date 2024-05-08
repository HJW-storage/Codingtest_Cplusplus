// https://www.acmicpc.net/problem/10814


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
typedef pair<pair<int, int>, string> P;

vector<P> vec;	// { {나이, 가입 순서}, 이름}

bool cmp(P &a, P &b) {
	if (a.first.first == b.first.first) return a.first.second < b.first.second;
	return a.first.first < b.first.first;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int _tmp = 0;
	string _str = "";
	for (int i = 0; i < n; i++) {
		cin >> _tmp >> _str;
		vec.push_back({ {_tmp, i}, _str });
	}

	sort(vec.begin(), vec.end(), cmp);
	for (P &it : vec) cout << it.first.first << " " << it.second << "\n";

	return 0;
}