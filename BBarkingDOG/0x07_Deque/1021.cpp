// https://www.acmicpc.net/problem/1021

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
#define max_n 54

int n = 0, m = 0, pop_arr[max_n] = { 0, }, res = 0;
deque<int> dq;

int solve() {
	int arr_idx = n-1; // 덱의 크기(길이) 
	int cycle_cnt = m; 
	int idx_pop = 0; // 뽑아 내려고 하는 수의 인덱스.
	int check = 0; // 2번, 3번 연산 중 어느 것을 할지 판단하기 위한 변수
	int _tmp = 0; 

	while (cycle_cnt > 0 && idx_pop < m) {

		// 뽑아내고자하는 수가 덱의 어느 위치(인덱스)에 있는지 찾는다.
		for (int k = 0; k <= arr_idx; k++) {
			if (dq[k] == pop_arr[idx_pop]) {
				check = k;
				break; // 탈출.
			}
		}

		// 찾아내고자 하는 수가 바로 앞에 있다면, 2,3번 연산 없이 바로 pop한다.
		if (check == 0) {
			dq.pop_front();
			cycle_cnt--;
			arr_idx--;
			idx_pop++;
		}
		// 2번 연산이 최소인 경우.
		else if (check <= arr_idx / 2) {
			// 찾고자 하는 수를 deque의 가장 front에 가져다 놓기 위해 반복.
			while (check--) {
				_tmp = dq.front();
				dq.pop_front();
				dq.push_back(_tmp);
				res++;
			}
			// 찾고자 하는 수가 deque의 맨 앞에 위치함.
			dq.pop_front();
			cycle_cnt--;
			arr_idx--;
			idx_pop++;
		}
		// 3번 연산이 최소인 경우.
		else if (check > arr_idx / 2) {
			// 찾고자 하는 수를 deque의 가장 front에 가져다 놓기 위해 반복.
			int _cnt = arr_idx + 1 - check;
			while (_cnt--) {
				_tmp = dq.back();
				dq.pop_back();
				dq.push_front(_tmp);
				res++;
			}
			// 찾고자 하는 수가 deque의 맨 앞에 위치함.
			dq.pop_front();
			cycle_cnt--;
			arr_idx--;
			idx_pop++;
		}
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> pop_arr[i];
	}

	// deque 1~n 까지 기본 세팅. 
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	cout << solve() << "\n";
	return 0;
}