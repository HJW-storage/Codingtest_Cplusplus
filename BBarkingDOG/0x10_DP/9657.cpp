// https://www.acmicpc.net/problem/9657

// 완전탐색 -> O(3^250) 시간초과
// dp로 풀자.

#include <iostream>
#include <algorithm>
using namespace std;

#define SangGeun 0
#define Changyoung 1


int n = 0, dp[1004] = { 0, };
void solve_dp() {
	// 두 사람(상근, 창영)이가 게임을 완벽 숙지 = 무조건 이기는 방법으로 진행한다.
	// 따라서, 선공이 누군지도 중요하게 작용한다.
	// -> 만약, 선공(상근)이가 한번이라도 이기는 경우가 있으면 상근이가 이긴걸로 간주한다.

	// dp[i]가 되는 경우는 dp[i-1], dp[i-3], dp[i-4] 에서 오는 경우
	// dp[] 배열에 저장하는 값은 누가 이겼는지, 상근이와 창영이 중에서 누가 이긴지를 표시

	// 초기화
	fill(&dp[0], &dp[0] + 1004, -1);

	// 기저사례
	dp[1] = SangGeun;
	dp[2] = Changyoung;
	dp[3] = SangGeun;
	dp[4] = SangGeun;

	// 메모리제이션, 로직 구현
	for (int i = 5; i <= n; i++) {
		int sum = dp[i - 1] + dp[i - 3] + dp[i - 4];
		// 이전 dp 배열에서 창영이에서 오는 경우라면 결국 상근이가 마지막 돌맹이를 가져가는 것이므로
		// 창영이에서 오는 경우가 한개라도 있으면 sum > 0 이기에 해당 dp 배열에는 상근이가 이긴 것이기에 상근을 저장한다.
		if (sum > 0) {
			dp[i] = SangGeun;
		}
		else {
			dp[i] = Changyoung;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	solve_dp();
	if (dp[n] == SangGeun) cout << "SK" << "\n";
	else if (dp[n] == Changyoung) cout << "CY" << "\n";
	return 0;
}