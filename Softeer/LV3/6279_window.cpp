// https://softeer.ai/practice/6279
// ������ ����â�� �����Ͽ� Ž�� = �����̵� ������ = �׸���
// �ִ� �ð� -> O(20000  X 10) 

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, k = 0, res = 0;
string hp_str = "";

void sliding_window() {
	for (int i = 0; i < n; i++) {
		if (hp_str[i] == 'P') {
			int start_win = i - k; // ������ ���� ��ǥ
			if (start_win < 0) start_win = 0;
			int end_win = i + k; // ������ �� ��ǥ
			if (end_win >= n) end_win = n - 1;
			
			for (int t = start_win; t <= end_win; t++) {
				if (hp_str[t] == 'H') {
					res++;
					// ��ǰ�� �������� ���� ��ǰ 'x' ���� �ʱ�ȭ + �κ��� 'x' ���� �ʱ�ȭ
					hp_str[t] = 'x'; // ��ǰ �ʱ�ȭ
					hp_str[i] = 'x'; // �κ� �ʱ�ȭ
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