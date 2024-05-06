// https://www.acmicpc.net/problem/1780
// 1 ¡Â N ¡Â 3^7(2187) 

#include <iostream>
#include <algorithm>

using namespace std;
#define max_n 3000
#define Minus_One 0
#define Zero 1
#define Plus_One 2

int res[3] = { 0, };
int n = 0, grid[max_n][max_n] = { 0, };

bool check_SameNum(int &_r, int &_c, int &_len) {
	bool flag = true;
	int check_num = grid[_r][_c];
	for (int r = _r; r < _r + _len; r++) {
		for (int c = _c; c < _c + _len; c++) {
			if (grid[r][c] != check_num) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
void go(int s_r, int s_c, int len) {
	if (check_SameNum(s_r, s_c, len)) {
		res[grid[s_r][s_c] + 1]++;
		return;
	}
	else {
		int gap = len / 3;
		go(s_r, s_c, gap);
		go(s_r, s_c + gap, gap);
		go(s_r, s_c + 2*gap, gap);
		go(s_r + gap, s_c, gap);
		go(s_r + gap, s_c + gap, gap);
		go(s_r + gap, s_c + 2 * gap, gap);
		go(s_r + 2 * gap, s_c, gap);
		go(s_r + 2 * gap, s_c + gap, gap);
		go(s_r + 2 * gap, s_c + 2 * gap, gap);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	/*cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}*/
	go(0, 0, n);
	cout << res[Minus_One] << "\n";
	cout << res[Zero] << "\n";
	cout << res[Plus_One] << "\n";

	return 0;
}