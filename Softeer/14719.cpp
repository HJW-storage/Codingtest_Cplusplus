// https://www.acmicpc.net/problem/14719
// 풀이 소요시간 : 40분
// 시간복잡도 : O(H*W) -> 최대 O(500 * 500)

#include <iostream>
#include <algorithm>
using namespace std;

int h = 0, w = 0, rain[504][504] = {0,}, res = 0;
int solve() {
	for (int i = 0; i < h; i++) {
		int prev_idx = -1; // 초기화
		for (int j = 0; j < w; j++) {
			if (rain[i][j] == 1) {
				// 맨처음 시작에 대한 if 예외처리.
				if (prev_idx == -1) { prev_idx = j; }
				else {
					res += j - prev_idx - 1;
					prev_idx = j; // 업데이트
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
			rain[h - 1 - k][i] = 1; // 블록을 1로 쌓아서 표시
		}
	}
	
	cout << solve() << "\n";
	return 0;
}

// test-case
// 4 11
// 3 1 2 3 4 1 1 2 1 1 2
// output : 7