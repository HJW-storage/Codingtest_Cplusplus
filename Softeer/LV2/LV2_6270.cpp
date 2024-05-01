// https://softeer.ai/practice/6270

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, m = 0, limit[104] = { 0, }, real[104] = { 0, };

int solve() {
	int res = 0;

	int diff = 0;
	for (int i = 1; i <= 100; i++) {
		diff = real[i] - limit[i];
		if (diff < 0) continue;
		res = max(res, diff);
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	
	int tmp1 = 0, tmp2 = 0, idx = 1;
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		while (tmp1--) {
			limit[idx++] = tmp2;
		}
	}

	idx = 1; // √ ±‚»≠
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		while (tmp1--) {
			real[idx++] = tmp2;
		}
	}

	cout << solve() << "\n";

	return 0;
}