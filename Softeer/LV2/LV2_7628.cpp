// https://softeer.ai/practice/7628

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, radian[104] = { 0, }, res = 0;;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int tmp_r = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp_r;
		for (int j = 2; j <= tmp_r; j++) {
			if (tmp_r % j == 0) radian[j]++;
		}
	}

	for (int i = 2; i <= 100; i++) {
		res = max(res, radian[i]);
	}
	cout << res << "\n";

	return 0;
}