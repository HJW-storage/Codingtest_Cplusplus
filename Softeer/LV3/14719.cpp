// https://www.acmicpc.net/problem/14719
// Ǯ�� �ҿ�ð� : 40��
// �ð����⵵ : O(H*W) -> �ִ� O(500 * 500)

#include <iostream>
#include <algorithm>
using namespace std;

int h = 0, w = 0, rain[504][504] = {0,}, res = 0;
int solve() {
	for (int i = 0; i < h; i++) {
		int prev_idx = -1; // �ʱ�ȭ
		for (int j = 0; j < w; j++) {
			if (rain[i][j] == 1) {
				// ��ó�� ���ۿ� ���� if ����ó��.
				if (prev_idx == -1) { prev_idx = j; }
				else {
					res += j - prev_idx - 1;
					prev_idx = j; // ������Ʈ
				}
			}
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int height = 0;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> height;
		for (int k = 0; k < height; k++) {
			rain[h - 1 - k][i] = 1; // ����� 1�� �׾Ƽ� ǥ��
		}
	}
	
	cout << solve() << "\n";
	return 0;
}

// test-case
// 4 11
// 3 1 2 3 4 1 1 2 1 1 2
// output : 7