//https://softeer.ai/practice/6280

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

int n = 0;
ll res[20] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	res[0] = 4; // �ʱⰪ.
	res[1] = 9;
	for (int i = 2; i <= n; i++) {
		int a = int((pow(2, i) - 1) / 2);
		//cout << "a : " << a << "\n";
		res[i] = res[i - 1] + (pow(4, i) - (2*a*(a+1)) + pow(4, i-1));
	}


	cout << res[n] << "\n";

	return 0;
}