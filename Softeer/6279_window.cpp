// https://softeer.ai/practice/6279
// 윈도우 조사창을 설정하여 탐색 = 슬라이딩 윈도우 = 그리디
// 최대 시간 -> O(20000  X 10) 

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, k = 0, res = 0;
string hp_str = "";

void sliding_window() {
	for (int i = 0; i < n; i++) {
		if (hp_str[i] == 'P') {
			int start_win = i - k; // 윈도우 시작 좌표
			if (start_win < 0) start_win = 0;
			int end_win = i + k; // 윈도우 끝 좌표
			if (end_win >= n) end_win = n - 1;
			
			for (int t = start_win; t <= end_win; t++) {
				if (hp_str[t] == 'H') {
					res++;
					// 부품을 집었으면 집은 부품 'x' 으로 초기화 + 로봇도 'x' 으로 초기화
					hp_str[t] = 'x'; // 부품 초기화
					hp_str[i] = 'x'; // 로봇 초기화
					break;
				}
			}
		}
	}
	cout << res << "\n";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;
	cin >> hp_str;
	sliding_window();

	return 0;
}