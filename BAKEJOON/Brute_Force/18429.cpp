// https://www.acmicpc.net/problem/18429
// cur_wei �ʱ�ȭ�� ���Ծ ����� �����ߵ�.... 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0, k = 0, plus_wei[10] = { 0, }, cur_wei = 500, cnt = 0;

void printV(vector<int>& t_vec) {
	for (int it : t_vec) cout << it << " ";
	cout << "\n";
	return;
}

bool solve(vector<int>& t_vec) {
	// cur_wei �ʱ�ȭ
	cur_wei = 500;

	bool flag = true;
	for (int it : t_vec) {
		cur_wei += plus_wei[it]; // � ŰƮ�� �ش��ϴ� ��ŭ �߷��� ��������. 
		cur_wei -= k;	// ������ k �� ������.
		
		if (cur_wei < 500) {
			flag = false;
			break;
		}
	}
	return flag;
}

void make_permutation(int depth, vector<int> &vec) {
	if (depth == n) {
		//printV(vec);
		
		// ���� ����
		// 1�������� N���������� ��� �Ⱓ����, � ���������� �߷��� 500���� �۾����� �ʵ��� �ؾ� �Ѵ�.
		if (solve(vec)) cnt++;
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(vec[i], vec[depth]);
		make_permutation(depth + 1, vec);
		swap(vec[i], vec[depth]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		v[i] = i; // ���� v�� �ε����� ��� ����. �ε��� �ʱ�ȭ
		cin >> plus_wei[i];
	}

	make_permutation(0, v);
	cout << cnt << "\n";

	return 0;
}

// TC-1
// 1 50
// 20
// expect : 0
// output : 0

// TC-2
// 1 1
// 1
// expect : 1
// output : 1

// TC-3
// 8 1
// 1 1 1 1 1 1 1 1
// expect : 40320
// output : 40320

// TC-4
// 3 4
// 7 5 3
// output : 4