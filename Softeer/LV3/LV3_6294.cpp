// https://softeer.ai/practice/6294

#include <iostream>
#include <algorithm>

using namespace std;

#define max_n 1000004
int n = 0, k = 0;
float score[max_n] = { 0, };

float solve(int &a, int &b) {
	return float(score[b] - score[a - 1]) / float(b - (a - 1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	int tmp_sco = 0;
	for (int i = 1; i <= n; i++) {
		cin >> tmp_sco;
		score[i] = score[i - 1] + tmp_sco;
	}
	int a1 = 0, b1 = 0;
	for (int i = 1; i <= k; i++) {
		cin >> a1 >> b1;
		printf("%.2f\n", solve(a1, b1));
	}

	return 0;
}