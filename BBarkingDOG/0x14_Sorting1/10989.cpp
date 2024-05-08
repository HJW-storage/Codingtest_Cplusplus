// https://www.acmicpc.net/problem/10989

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 10'004

int n = 0, arr[max_n] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int _tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> _tmp;
		arr[_tmp]++;
	}

	// Ãâ·Â
	for (int i = 1; i < max_n; i++) {
		while (arr[i]--) {
			cout << i << "\n";
		}
	}
	return 0;
}