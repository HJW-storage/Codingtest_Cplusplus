// https://www.acmicpc.net/problem/7795

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case = 0, A = 0, B = 0;

int solve(vector<int> &t1, vector<int> &t2) {
	int res = 0;
	int idx_1 = 0, size_1 = t1.size();
	int idx_2 = 0, size_2 = t2.size();

	while (1) {
		if (idx_1 >= size_1 || idx_2 >= size_2) break;

		if (t1[idx_1] > t2[idx_2]) {
			res += size_1 - idx_1;
			idx_2++;
		}
		else if (t1[idx_1] <= t2[idx_2]) {
			idx_1++;
		}
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> test_case;
	while (test_case--) {
		cin >> A >> B;
		vector<int> v1(A, 0);
		vector<int> v2(B, 0);

		for (int i = 0; i < A; i++) {
			cin >> v1[i];
		}
		for (int i = 0; i < B; i++) {
			cin >> v2[i];
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		cout << solve(v1, v2) << "\n";
	}

	return 0;
}