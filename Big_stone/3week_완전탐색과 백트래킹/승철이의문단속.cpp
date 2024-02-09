#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int n = 0;

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int go(int idx, int sum) {
	if (idx == n) {
		return check(sum);
	}
	
	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	cout << go(0, 0) << "\n";
	return 0;
}