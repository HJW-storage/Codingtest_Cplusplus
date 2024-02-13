// https://www.acmicpc.net/problem/14501

// 삼성 SW 역량 테스트 기출문제.
// dp를 뒤에서부터 해오는게 가장 빠르고 쉬운풀이인 새로운 시각을 본 문제다..
// dp를 반드시 앞에서부터 하라는 고정관념을 꺠뜨린 문제!!

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, T[20] = { 0, }, P[20] = { 0, }, dp[20] = {0,};

void solve_dp() {
	// 메모리제이션, 로직 구현
	for (int i = n; i > 0; i--) {
		int dealline = i + T[i];
		if (dealline > n + 1) {
			// 상담 불가
			dp[i] = dp[i + 1];
		}
		else {
			// 상담 가능
			dp[i] = max(dp[i + 1], dp[dealline] + P[i]);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	solve_dp();
	cout << dp[1] << "\n";

	return 0;
}