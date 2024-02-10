// https://www.acmicpc.net/problem/15989
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll n = 0, t = 0, res = 0;
// 완전탐색 시간초과... DP를 이용하자. 
//void solve(ll here, ll sum) {
//	// 기저 사례
//	if (sum == n) {
//		res++;
//		return;
//	}
//	else if (sum > n) {
//		return;
//	}
//
//	// 로직
//	// 문제 결과값은 순서를 고려하지 않기에, 모든 경우에 1,2,3으로 가지 않는다.
//	// 중복을 제거해야 한다.
//	if (here == 0) {	// 초기 처음 시작 0은 1,2,3으로 다 뿌려준다.
//		solve(1, sum + 1);
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 1) {
//		solve(1, sum + 1);
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 2) {
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 3) {
//		solve(3, sum + 3);
//	}
//	return;
//}

ll dp[10004] = { 0, };
void DP() {
	// 기저사례
	dp[0] = 1;

	// 메모리제이션
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			if(j-i >= 0) dp[j] += dp[j - i];
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	DP(); // DP를 통해 메모리제이션 진행. 

	for (ll i = 0; i < t; i++) {
		cin >> n;
		// 완전탐색 ------------------
		//res = 0; // 초기화
		//solve(0, 0);
		//cout << "출력 : " << res << "\n";
		// 완전탐색 ------------------

		// DP()
		cout << dp[n] << "\n";
		//cout << "결과 : " << dp[n] << "\n";
	}

	return 0;
}