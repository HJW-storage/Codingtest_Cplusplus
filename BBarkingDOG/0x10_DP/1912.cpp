// https://www.acmicpc.net/problem/1912
// ��Ž �Ұ�. dp �̿�.

#include <iostream>
#include <algorithm>

using namespace std;
#define max_n 100'004

int n = 0, arr[max_n] = { 0, }, dp[max_n] = { 0, };

int solve_dp() {
	// �ʱ�ȭ
	fill(&dp[0], &dp[0] + max_n, -1004); // ��û ���� ���� �ʱ�ȭ.
	dp[1] = arr[1];

	// �޸����̼�, ��������
	// �׾ƿ��鼭 �ִ��� ���ϱ�.
	for (int i = 2; i <= n; i++) {
		// ����(1) + ����(2) �̸� �� ���� ���� �ǹǷ� ������ �ʴ´�. ����(2)�� ����.
		if (dp[i - 1] < 0 && arr[i] < 0) {
			dp[i] = arr[i];
		}
		// ����(1) + ���(2) �̸� ���� ���� �ǹǷ� ������ �ʴ´�. ���(2)�� ����.
		else if (dp[i - 1] < 0 && arr[i] >= 0) {
			dp[i] = arr[i];
		}
		// ���(1) + ����(2) �̸� ���Ѵ� => ����, ���ӵ� ���� ���� ����ϴ� ���̹Ƿ�, �������� ����� �ִ� ��� �����ִ� ¡�˴ٸ� ����
		else if (dp[i - 1] >= 0 && arr[i] < 0) {
			dp[i] = dp[i-1] + arr[i];
		}
		// ���(1) + ���(2) �̸� ���Ѵ�
		else if (dp[i - 1] >= 0 && arr[i] >= 0) {
			dp[i] = dp[i - 1] + arr[i];
		}
	}

	// �ִ��� ã��.
	int max_res = -1004;
	for (int i = 1; i <= n; i++) {
		max_res = max(max_res, dp[i]);
	}

	return max_res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << solve_dp() << "\n";
	return 0;
}