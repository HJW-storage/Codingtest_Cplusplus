// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <algorithm>

using namespace std;
#define max_n  134
#define WHITE    0
#define BLUE     1


int n = 0, color_paper[max_n][max_n] = { 0, }, res[2] = {0, 0};

bool Check_SameColor(int r, int c, int len) {
	bool same_color = true;
	int check_color = color_paper[r][c];

	for (int i = r; i < r + len; i++) {
		for (int j = c; j < c + len; j++) {
			if (color_paper[i][j] != check_color) {
				same_color = false;
				break;
			}
		}
	}
	return same_color;
}
void go(int s_r, int s_c, int s_len) {
	// 탈출 조건
	if (Check_SameColor(s_r, s_c, s_len)) {
		if (color_paper[s_r][s_c] == WHITE) res[WHITE]++;
		else res[BLUE]++;
		return; // 종료
	}

	go(s_r, s_c, s_len / 2);
	go(s_r, s_c + s_len / 2, s_len / 2);
	go(s_r + s_len / 2, s_c, s_len / 2);
	go(s_r + s_len / 2, s_c + s_len / 2, s_len / 2);
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color_paper[i][j];
		}
	}

	/*cout << "\n"; cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << color_paper[i][j] << " ";
		}
		cout << "\n";
	}*/

	go(0, 0, n);
	cout << res[WHITE] << "\n";
	cout << res[BLUE] << "\n";
	return 0;
}


/*
TC-1
<input>
2
0 1
0 1
<output>
2
2

TC-2
<input>
2
0 0
0 0
<output>
1
0

TC-3
<input>
2
1 1
1 1
<output>
0
1

TC-4
<input>
2
0 1
1 0
<output>
2
2

*/