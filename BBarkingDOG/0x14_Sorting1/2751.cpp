// https://www.acmicpc.net/problem/2751

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (int& it : v) cout << it << "\n";

	return 0;
}