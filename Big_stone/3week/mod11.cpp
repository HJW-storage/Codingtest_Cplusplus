#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int n = 0, result = 0;
const int mod = 11;

void go(int idx, int sum) {
	if (result == mod - 1) return;
	if (idx == n) {
		result = max(result, sum % mod);
		return;
	}

	go(idx + 1, sum + v[idx]);
	go(idx + 1, sum);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	go(0, 0);
	cout << result << "\n";
	return 0;
}