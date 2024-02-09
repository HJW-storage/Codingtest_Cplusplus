// https://www.acmicpc.net/problem/3474

#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;

	// 소인수 분해의 개념에서 2와 5의 곱으로만 10이 만들어진다.
	// 문제를 분석하다보니 2의 개수는 5의 개수 보다 항상 많다. 
	// 따라서 5의 지수 개수만 구해도 된다.
	for (int i = 0; i < test_case; i++) {
		int n = 0;
		cin >> n;

		ll sqrt_5 = 1;
		ll res = 0;
		while (sqrt_5 < n) {
			sqrt_5 = sqrt_5 * 5;
			res += n / sqrt_5;
		}
	cout << res << "\n";
	}

	return 0;
}