// https://softeer.ai/practice/6292
// 모듈러 연산을 알아야한다.

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define mod_n 1000000007
typedef long long ll;
map<int, int> mp;

ll K = 0, P = 0, N = 0, P_1sec = 1;
ll go(ll n) {
	// 기저사례
	if (n == 1) return P_1sec;

	// 메모리제이션
	if (mp[n] != 0) return mp[n];

	// 로직 구현
	if (n % 2 == 0) { // 짝수
		mp[n] = (go(n / 2) * go(n / 2)) % mod_n;
	}
	else { // 홀수
		mp[n] = (go(n / 2) * go(n / 2 + 1)) % mod_n;
	}
	return mp[n];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> K >> P >> N;

	// 0.1초당 P배 증가한다.
	// 1초당 증가하는 수의 나머지를 구한다.
	ll p1 = P % mod_n;
	for (int i = 1; i <= 10; i++) {
		P_1sec = (P_1sec * p1) % mod_n;
	}

	ll PN = go(N);
	ll res = (PN * (K % mod_n)) % mod_n;
	cout << res << "\n";
	return 0;
}