// https://www.acmicpc.net/problem/1165

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int n = 0;

bool cmp(pair<int, int>& ta, pair<int, int>& tb) {
	if (ta.second == tb.second) return ta.first < tb.first;
	return ta.second < tb.second;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);
	for (pair<int, int>& it : v) cout << it.first << " " << it.second << "\n";

	return 0;
}