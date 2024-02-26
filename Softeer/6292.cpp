// https://softeer.ai/practice/6292
// ��ⷯ ������ �˾ƾ��Ѵ�.

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define mod_n 1000000007
typedef long long ll;
map<ll, ll> mp;

ll K = 0, P = 0, N = 0, P_1sec = 1;
ll go(ll n) {
	// �������
	if (n == 1) return P_1sec;

	// �޸����̼�
	if (mp[n] != 0) return mp[n];

	// ���� ����
	if (n % 2 == 0) { // ¦��
		mp[n] = (go(n / 2) * go(n / 2)) % mod_n;
	}
	else { // Ȧ��
		mp[n] = (go(n / 2) * go(n / 2 + 1)) % mod_n;
	}
	return mp[n];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> K >> P >> N;

	// 0.1�ʴ� P�� �����Ѵ�.
	// 1�ʴ� �����ϴ� ���� �������� ���Ѵ�.
	ll p1 = P % mod_n;
	for (int i = 1; i <= 10; i++) {
		P_1sec = (P_1sec * p1) % mod_n;
	}

	ll PN = go(N);
	ll res = (PN * (K % mod_n)) % mod_n;
	cout << res << "\n";
	return 0;
}