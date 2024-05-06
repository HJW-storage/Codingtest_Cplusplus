// https://www.acmicpc.net/problem/1021

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
#define max_n 54

int n = 0, m = 0, pop_arr[max_n] = { 0, }, res = 0;
deque<int> dq;

int solve() {
	int arr_idx = n-1; // ���� ũ��(����) 
	int cycle_cnt = m; 
	int idx_pop = 0; // �̾� ������ �ϴ� ���� �ε���.
	int check = 0; // 2��, 3�� ���� �� ��� ���� ���� �Ǵ��ϱ� ���� ����
	int _tmp = 0; 

	while (cycle_cnt > 0 && idx_pop < m) {

		// �̾Ƴ������ϴ� ���� ���� ��� ��ġ(�ε���)�� �ִ��� ã�´�.
		for (int k = 0; k <= arr_idx; k++) {
			if (dq[k] == pop_arr[idx_pop]) {
				check = k;
				break; // Ż��.
			}
		}

		// ã�Ƴ����� �ϴ� ���� �ٷ� �տ� �ִٸ�, 2,3�� ���� ���� �ٷ� pop�Ѵ�.
		if (check == 0) {
			dq.pop_front();
			cycle_cnt--;
			arr_idx--;
			idx_pop++;
		}
		// 2�� ������ �ּ��� ���.
		else if (check <= arr_idx / 2) {
			// ã���� �ϴ� ���� deque�� ���� front�� ������ ���� ���� �ݺ�.
			while (check--) {
				_tmp = dq.front();
				dq.pop_front();
				dq.push_back(_tmp);
				res++;
			}
			// ã���� �ϴ� ���� deque�� �� �տ� ��ġ��.
			dq.pop_front();
			cycle_cnt--;
			arr_idx--;
			idx_pop++;
		}
		// 3�� ������ �ּ��� ���.
		else if (check > arr_idx / 2) {
			// ã���� �ϴ� ���� deque�� ���� front�� ������ ���� ���� �ݺ�.
			int _cnt = arr_idx + 1 - check;
			while (_cnt--) {
				_tmp = dq.back();
				dq.pop_back();
				dq.push_front(_tmp);
				res++;
			}
			// ã���� �ϴ� ���� deque�� �� �տ� ��ġ��.
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

	// deque 1~n ���� �⺻ ����. 
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	cout << solve() << "\n";
	return 0;
}