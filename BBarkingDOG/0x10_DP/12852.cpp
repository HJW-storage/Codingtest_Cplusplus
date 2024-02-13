// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <algorithm>
using namespace std;

// n에서 -> 1로 오는것으로 생각하면 어렵다.
// 역으로 생각해서
// 1에서 -> n을 만드는 것으로 생각.
// (1). 3의 배수이면 dp[i/3] 에서 3을 곱해서 오는 경우
// (2). 2의 배수이면 dp[i/2] 에서 2를 곱해서 오는 경우
// (3). 1을 더하는 경우

int n = 0;
int dp[1000004] = { 0, };

void solve_dp() {
	// 기저사례
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	// 메모리제이션, 로직 구현
	for (int i = 4; i <= n; i++) {
		// (0). i가 3의 배수이면서 2의 배수인 경우도 고려해주어야 한다.... !! 
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(min(dp[i - 1] + 1, dp[i / 3] + 1), dp[i / 2] + 1);
		}
		// (1). i가 3의 배수이면
		else if(i % 3 == 0){
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		// (2). i가 2의 배수이면
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		}
		// (3). 나머지
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	solve_dp();
	cout << dp[n] << "\n";
	while (n >= 1) {
		cout << n << " ";
		if (n % 3 == 0 && n % 2 == 0) {
			if (dp[n / 3] <= dp[n - 1] && dp[n / 3] <= dp[n / 2]) {
				n = n / 3;
			}
			else if (dp[n / 2] <= dp[n - 1] && dp[n / 2] <= dp[n / 3]) {
				n = n / 2;
			}
			else if (dp[n - 1] <= dp[n / 3] && dp[n - 1] <= dp[n / 2]) {
				n--;
			}
		}
		else if (n % 3 == 0) {
			n = dp[n / 3] <= dp[n - 1] ? n / 3 : n - 1;
		}
		else if (n % 2 == 0) {
			n = dp[n / 2] <= dp[n - 1] ? n / 2 : n - 1;
		}
		else {
			n--;
		}
	}

	return 0;
}