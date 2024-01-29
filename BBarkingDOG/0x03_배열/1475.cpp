// https://www.acmicpc.net/problem/1475

// 1. 숫자 배열을 만들어 카운팅
// 2. 단, 6과 9는 같이 올리자. (6 또는 9의 합친 개수가 1, 3, 5, 7 홀수개일떄 CNT 증가)
#include <iostream>
#include <algorithm>

using namespace std;
int num_arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string room_num;
	cin >> room_num;

	int flag_cnt = 0;
	int str_len = room_num.length();
	for (int i = 0; i < str_len; i++) {
		if (room_num[i] == '6' || room_num[i] == '9') {
			flag_cnt++;
			// 홀수 개 일때만 카운팅 (6과 9같이 카운팅)
			if (flag_cnt % 2 != 0) {
				num_arr[6]++;
				num_arr[9]++;
			}
		}
		else {
			num_arr[room_num[i] - '0']++;
		}
	}

	int res = 0;
	for (int i = 0; i < 10; i++) {
		res = max(res, num_arr[i]);
	}
	cout << res << "\n";

	return 0;
}