// https://www.acmicpc.net/problem/15684

#include <iostream>
#include <algorithm>
#include <vector>

#define max_n 987654321
using namespace std;

int n, m, h, res = max_n;
int game[31][11] = { 0, };

bool start_game(int start) {
	int cur_pos = start; // 사다리 게임에서의 현재 번호. 
	int tmp_depth = 1;
	while (tmp_depth != h + 1) {
		// 사다리가 있으면 이동하고 없으면 아래로 내려간다. 
		// 사다리는 연달아 있을 수는 없다. <- 문제 조건
		if (game[tmp_depth][cur_pos]) cur_pos++;
		else if (game[tmp_depth][cur_pos - 1]) cur_pos--;
		tmp_depth++; // 사다리 아래로 이동
	}
	if (cur_pos == start) { return true; }
	else { return false; }
}
bool check() {
	bool tmp = true;
	for (int i = 1; i <= n; i++) {
		tmp = start_game(i);
		if (tmp == false) break;
	}
	return tmp;
}
void go(int here, int cnt) {
	// 기저 사례
	if (cnt > 3 || cnt >= res) return;
	if (check()) {
		res = min(res, cnt);
		return;
	}

	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (game[i][j] || game[i][j + 1] || game[i][j-1]) { continue; }
			// 사다리 그리기 (방문처리)
			game[i][j] = 1;
			go(i, cnt + 1);
			// 원상 복구
			game[i][j] = 0;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// n : 세로선의 개수, m : 현재 그려져있는 가로선의 개수, h : 가로선을 그을 수 있는 점섬 개수
	cin >> n >> m >> h;
	if (m == 0) {
		cout << "0" << "\n";
		return 0;
	}
	int row = 0, col = 0;
	for (int i = 0; i < m; i++) {
		cin >> row >> col;
		// 사다리 경로를 1로 표시해서 이어준다.
		game[row][col] = 1;
	}

	go(1, 0);
	if (res == max_n) cout << "-1" << "\n";
	else cout << res << "\n";

	return 0;
}