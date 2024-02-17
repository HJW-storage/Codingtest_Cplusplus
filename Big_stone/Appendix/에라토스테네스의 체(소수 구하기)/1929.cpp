// https://www.acmicpc.net/problem/1929
// "에라토스테네스의 체" 알고리즘 활용문제.

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n = 0, m = 0, Sosu[1'000'004] = { 0, };

// 1은 소수가 아니다!! 
void print_sosu() {
	Sosu[1] = 1; // 1은 소수가 아님.

	// for (int i = 2; i*i <= n; i++)
	for (int i = 2; i <= sqrt(n); i++) {
		// 이미 지워진 수라면 이전 수의 배수라는 의미이므로 다음 수로 통과한다.
		if (Sosu[i] != 0) continue;
		for (int j = i; j <= n; j += i) {
			// 자기 자신은 소수이기에 다음 수로 점프. 
			if (j == i) continue;
			Sosu[j] = 1; // 소수가 아님을 표시. 
		}
	}

	// 정답(소수) 출력
	for (int k = m; k <= n; k++) {
		if (Sosu[k] == 1) continue;
		cout << k << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> m >> n;
	print_sosu();
	return 0;
}