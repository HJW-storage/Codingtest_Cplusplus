// https://www.acmicpc.net/problem/1149

// 완전탐색을 2^n 으로 시간초과.
// DP로 풀이. 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int n = 0, cost_arr[1004][3] = { 0, }, house[1004][3] = { 0, };
int DP() {
	// 기저사례
	house[1][RED] = cost_arr[1][RED];
	house[1][GREEN] = cost_arr[1][GREEN];
	house[1][BLUE] = cost_arr[1][BLUE];

	// 메모리제이션 & 로직
	// i번째 집을 빨강, 초록, 파랑으로 칠했을 때의 비용의 최솟값을 저장한다.
	for (int i = 2; i <= n; i++) {
		house[i][RED] = min(house[i-1][GREEN], house[i-1][BLUE]) + cost_arr[i][RED];
		house[i][GREEN] = min(house[i-1][RED], house[i-1][BLUE]) + cost_arr[i][GREEN];
		house[i][BLUE] = min(house[i-1][GREEN], house[i-1][RED]) + cost_arr[i][BLUE];
	}
	return min(min(house[n][RED], house[n][GREEN]), house[n][BLUE]);
}

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return;
}

// 완전탐색
//int n = 0, rgb_arr[1004][3], res = 987654321;
// 
//void Full_Search(int here, int sum, int prev_color, int pprev_color) {
//	// 종료조건
//	if (here == n) {
//		res = min(res, sum);
//		return;
//	}
//
//	// 로직 구현
//	if (here == 0) {
//		// 시작은 R, G, B 로 가는 경우의수 3가지이다.
//		Full_Search(here + 1, sum + rgb_arr[here + 1][RED], RED, RED);
//		Full_Search(here + 1, sum + rgb_arr[here + 1][GREEN], GREEN, GREEN);
//		Full_Search(here + 1, sum + rgb_arr[here + 1][BLUE], BLUE, BLUE);
//	}
//	else{
//		// here == 1, n-1 일 때 경우의수는 2가지.
//		int tmp_color = prev_color + 1;
//		if (tmp_color > 2) tmp_color = tmp_color - 3;
//		Full_Search(here + 1, sum + rgb_arr[here + 1][tmp_color], tmp_color, prev_color);
//		
//		int ttmp_color = prev_color + 2;
//		if (ttmp_color > 2) ttmp_color = ttmp_color - 3;
//		Full_Search(here + 1, sum + rgb_arr[here + 1][ttmp_color], ttmp_color, prev_color);
//	}
//
//	return;
//}

int main() {
	fast_io();

	cin >> n;
	/*for (int i = 1; i <= n; i++) {
		cin >> rgb_arr[i][RED] >> rgb_arr[i][GREEN] >> rgb_arr[i][BLUE];
	}
	Full_Search(0, 0, RED, RED);
	cout << res << "\n";*/

	for (int i = 1; i <= n; i++) {
		cin >> cost_arr[i][RED] >> cost_arr[i][GREEN] >> cost_arr[i][BLUE];
	}
	cout << DP() << "\n";
	return 0;
}