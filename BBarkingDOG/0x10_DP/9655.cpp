// https://www.acmicpc.net/problem/9655

// DP로 구현이 되지만 그냥 단순 로직으로 풀이가 가능했다.

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	if (n % 2 == 0) {
		cout << "CY" << "\n";
	}
	else {
		cout << "SK" << "\n";
	}

	return 0;
}
