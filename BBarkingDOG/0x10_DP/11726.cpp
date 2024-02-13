// https://www.acmicpc.net/problem/11726

// 블럭들의 규칙만 찾아주면 되거든요.
// 한번에 블록은 한칸씩 늘어나고요. 그럼 블록이 한칸 늘어났을떄, 어떻게 해야 하는가에 대하여 생각 해 봅시다.
// N번째 블록을 만드려면, 우선 N - 1 번째 블록에서 딱 1만 큼 공간이 증가하였기에, N - 1 번째 블록에 ㅣ 이거를 붙여주면 됩니다.
// 그럼 2칸짜린데 어떻게 해야 할까요 ? 2칸전꺼에서 = 이블록을 붙여주면 됩니다.
// 그럼 N 번째 블록의 갯수는 ? " N - 1 + N - 2 "가 되네요

#include <iostream>
#include <algorithm>
using namespace std;

#define mod_n 10007
int n = 0;
int dp[1004] = { 0, };

int DP() {
	// 기저사례
	dp[1] = 1;
	dp[2] = 2;

	// 메모리제이션, 로직 구현
	for (int i = 3; i <= n; i++) {
		// 모듈러 연산 법칙
		// 더한 수의 나머지는 = 덧셈전의 수의 나머지들의 합과 같다.
		dp[i] = (dp[i - 1] % mod_n + dp[i - 2] % mod_n) % mod_n;
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cout << DP() << "\n";
	return 0;
}