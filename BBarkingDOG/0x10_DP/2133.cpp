// https://www.acmicpc.net/problem/2133
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, dp[34] = { 0, };
void solve_dp() {
    // 기저 사례
    dp[2] = 3;
    dp[4] = 3*3 + 2;

    // 메모리 제이션, 로직 구현
    for (int i = 6; i <= n; i += 2) {
        int tmp = 0;
        for (int j = i - 4; j >= 2; j--) {
            tmp += dp[j] * 2;
        }
        dp[i] = (dp[i - 2] * 3 + tmp) + 2;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    solve_dp();
    cout << dp[n] << "\n";
    return 0;
}