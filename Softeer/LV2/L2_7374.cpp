// https://softeer.ai/practice/7374

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int grid[3][3] = { 0, };
priority_queue<int, vector<int>, greater<int>> pq;

void find_mid_val_and_solve(P &p1, P& p2, P& p3) {
	// �Ű������δ� ��� ���� �޾ƿ´�.
	// �־��� ��� ���� �ش��ϴ� ��ǥ���� �߰� ���� ã�´�. 

	int first_val = 0, second_val = 0, third_val = 0, mx_val = 0, mn_val = 0, mid_val = 0;

	first_val = grid[p1.first][p1.second];
	second_val = grid[p2.first][p2.second];
	third_val = grid[p3.first][p3.second];
	int sum_val = first_val + second_val + third_val;

	mx_val = max({ first_val, second_val, third_val });
	mn_val = min({ first_val, second_val, third_val });
	mid_val = sum_val - mx_val - mn_val;

	int tmp_val = 0;
	tmp_val = abs(mx_val - mid_val) + abs(mid_val - mn_val);

	// ������ ���� �Ǳ� ���� �ּ� ���� <�켱���� ť>�� ����.
	pq.push(tmp_val);

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> grid[i][j];
		}
	}


	// �� ���� �� Ž��
	for(int i = 0; i < 3; i++) {
		P t1 = { i, 0 };
		P t2 = { i, 1 };
		P t3 = { i, 2 };
		find_mid_val_and_solve(t1, t2, t3);
	}

	// �� ���� �� Ž��
	for (int i = 0; i < 3; i++) {
		P t1 = { 0, i };
		P t2 = { 1, i };
		P t3 = { 2, i };
		find_mid_val_and_solve(t1, t2, t3);
	}

	cout << pq.top() << "\n";
	return 0;
}