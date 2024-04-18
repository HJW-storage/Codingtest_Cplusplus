// https://softeer.ai/practice/6268

#include <iostream>
#include <algorithm>
using namespace std;

int FND[10][7] = {
//   0  1  2  3  4  5  6 
	{1, 1, 1, 1, 1, 1, 0},	// FND : 0 
	{0, 1, 1, 0, 0, 0, 0},	// FND : 1 
	{1, 1, 0, 1, 1, 0, 1},	// FND : 2 
	{1, 1, 1, 1, 0, 0, 1},	// FND : 3 
	{0, 1, 1, 0, 0, 1, 1},	// FND : 4 
	{1, 0, 1, 1, 0, 1, 1},	// FND : 5 
	{1, 0, 1, 1, 1, 1, 1},	// FND : 6 
	{1, 1, 1, 0, 0, 1, 0},	// FND : 7 
	{1, 1, 1, 1, 1, 1, 1},	// FND : 8 
	{1, 1, 1, 1, 0, 1, 1},	// FND : 9 
};

int solve(int a, int b) {
	// �����ڸ�, õ���ڸ�, �����ڸ�, �����ڸ�, �����ڸ��� ���Ѵ�.
	int tmp_a[5] = { 0, }, tmp_b[5] = { 0, };

	int idx = 0;
	for (int i = 10000; i >= 10; i = i / 10) {
		tmp_a[idx] = a / i;
		a = a % i;

		tmp_b[idx] = b / i;
		b = b % i;

		idx++;
	}
	tmp_a[idx] = a;
	tmp_b[idx] = b;


	// ���ؼ� ����ġ �� ���ϱ�
	bool a_start = false, b_start = false;
	int push_sw_cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (tmp_a[i] > 0) a_start = true;
		if (tmp_b[i] > 0) b_start = true;

		if (a_start == true && b_start == true) { // ���� idx �迭 �� Ʋ�� �κ� ���� ����.
			for (int j = 0; j < 7; j++) {
				if (FND[tmp_a[i]][j] == FND[tmp_b[i]][j]) continue;
				push_sw_cnt++;
			}
		}
		else if (a_start == true && b_start == false) { // a���� b�� �ٲٴ� ��.
			for (int j = 0; j < 7; j++) {
				if (!FND[tmp_a[i]][j]) continue;
				push_sw_cnt++; // a�� ���� �ְ�, b�� ���� ����. a�� �� ����. 
			}
		}
		else if (a_start == false && b_start == true) { // a���� b�� �ٲٴ� ��.
			for (int j = 0; j < 7; j++) {
				if (!FND[tmp_b[i]][j]) continue;
				push_sw_cnt++; // a�� ���� djqt��, b�� �� ����. b�� �ش��ϴ� ��� Ų��. 
			}
		}
		else if (a_start == false && b_start == false) { // a���� b�� �ٲٴ� ��.
			;
		}

	}

	return push_sw_cnt;
}
int A = 0, B = 0, T = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << solve(A, B) << "\n";
	}

	return 0;
}