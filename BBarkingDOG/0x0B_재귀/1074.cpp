// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

unsigned int N = 0, r = 0, c = 0;

// 문제의 첫번째 방문은 0으로 간주하고 두번째 방문부터 카운팅 한다.
// 따라서, cnt = -1; 부터 시작.
//int res = 0, cnt = -1;
//bool _find = false;
// 완탐 -> 시간 초과... 
//void go(int s_row, int s_col, int len) {
//	// 종료 조건
//	if (len == 1) {
//		if (s_row == r && s_col == c) {
//			_find = true;
//			res = ++cnt;
//		}
//		else {
//			cnt++;
//		}
//		return;
//	}
//
//	// 재귀 go
//	if (!(_find)) go(s_row, s_col, len / 2);
//	if (!(_find)) go(s_row, s_col + len / 2, len / 2);
//	if (!(_find)) go(s_row + len / 2, s_col, len / 2);
//	if (!(_find)) go(s_row + len / 2, s_col + len / 2, len / 2);
//
//	return;
//}

int arr[20] = { 0, };	
// 시간복잡도 : O(N) 
void solve(int s_row, int s_col, int len, int depth_cnt) {
	if (depth_cnt == N) return;

	int tmp_cnt = 0;
	// 재귀 
	if (r >= s_row && r < s_row + len / 2 && c >= s_col && c < s_col + len / 2) {
		arr[depth_cnt] = tmp_cnt;
		solve(s_row, s_col, len / 2, depth_cnt+1);
	}
	else tmp_cnt++;

	if (r >= s_row && r < s_row + len / 2 && c >= s_col + len / 2 && c < s_col + len) {
		arr[depth_cnt] = tmp_cnt;
		solve(s_row, s_col + len / 2, len / 2, depth_cnt + 1);
	}

	else tmp_cnt++;
	if (r >= s_row + len / 2 && r < s_row + len && c >= s_col && c < s_col + len / 2) {
		arr[depth_cnt] = tmp_cnt;
		solve(s_row + len / 2, s_col, len / 2, depth_cnt + 1);
	}
	else tmp_cnt++;

	if (r >= s_row + len / 2 && r < s_row + len  && c >= s_col + len / 2 && c < s_col + len) {
		arr[depth_cnt] = tmp_cnt;
		solve(s_row + len / 2, s_col + len / 2, len / 2, depth_cnt + 1);
	}
	else tmp_cnt++;

	return;
}

int calculate_ans(int _arr[], int n_len) {
	int res = 0;
	for (int i = 0; i < n_len; i++) {
		res += _arr[i] * (pow(2, n_len - 1 - i) * pow(2, n_len - 1 - i));
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> r >> c;

	solve(0, 0, int(pow(2, N)), 0);
	cout << calculate_ans(arr, N) << "\n";

	return 0;
}