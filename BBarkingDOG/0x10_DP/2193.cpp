// https://www.acmicpc.net/problem/2193

// 자료형 int로 하면 틀린다. -> 어립잡아 0,1 이  90번 번갈아 오기에 2^90으로 하는 경우 자료형 초과다.
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll; 
ll n = 0, dp[2][94] = { 0, };

// dp[해당 값으로 끝나는 경우][idx]
// dp[0][idx] : 0으로 끝나는 경우
// dp[1][idx] : 1으로 끝나는 경우
ll solve_dp() {
	// 초기화
	dp[0][1] = 0; 
	dp[1][1] = 1; 

	// 메모리제이션, 로직구현
	for(int i=2;i<=n;i++){
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	return (dp[0][n] + dp[1][n]);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solve_dp() << "\n";
	return 0;
}