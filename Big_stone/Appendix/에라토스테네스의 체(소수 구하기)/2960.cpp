// https://www.acmicpc.net/problem/2960
// "에라토스테네스의 체" 

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n = 0, k = 0, Eratos[1004] = { 0, };

int solve_eratos() {
	int cnt = 1, res = 0;
	for (int i = 2; i <= n; i++) {
		if (Eratos[i]) continue; // 이전에 지워진 수라면 점프
		for (int j = i; j <= n; j += i) {
			if (Eratos[j]) continue;
			if (cnt == k) res = j;
			Eratos[j] = cnt++; // 소수가 아니면 1을 채운다.
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	cout << solve_eratos() << "\n";
	return 0;
}