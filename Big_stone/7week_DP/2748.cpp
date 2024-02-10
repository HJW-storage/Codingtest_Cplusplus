// https://www.acmicpc.net/problem/2748

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n = 0;
ll fibo[94] = { 0, };

void solve_dp1() {
	// 기저사례
	fibo[0] = 0;
	fibo[1] = 1;

	// 메모리제이션 (bottom-up 방식)
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return;
}

ll solve_dp2(int idx)
{
	// 기저사례
	if (idx == 0) return 0;
	if (idx == 1) return 1;

	// 메모리제이션 (Top-down방식)
	if (fibo[idx] == 0) {
		fibo[idx] = solve_dp2(idx - 1) + solve_dp2(idx - 2);
	}
	return fibo[idx];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	//// bottom-up 방식
	//solve_dp1();
	//cout << fibo[n] << "\n";

	// top-down 방식
	cout << solve_dp2(n) << "\n";
	return 0;
}