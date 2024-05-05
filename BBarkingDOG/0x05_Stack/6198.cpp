// https://www.acmicpc.net/problem/6198
// �ڷ��� Ȯ�� ������. 
// ������ ������ 80,000�� �̴�. 
// ����, ������ 80,000���� ~ 1���� ������������ �־����� �� res = 80,000 + 79,999 + ... + 1  ~= 80,001 * 40,000 = 3,200,040,000 (�� 32��)
// �׷��⿡ �ڷ����� long long�� �Ǿ�� �Ѵ�!!!.

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;


#define max_hei_cnt 80004
int n = 0, building_hei[max_hei_cnt] = { 0, };
stack<int> stk;

ll calculate_buling_height() {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		while (stk.size() && stk.top() <= building_hei[i]) {
			stk.pop();
		}

		res += stk.size(); // ���� �ִ� ������ ũ�⸸ŭ �����ֱ�.
		stk.push(building_hei[i]); // ���� ���� ���ÿ� �ױ�.
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> building_hei[i];
	}

	cout << calculate_buling_height() << "\n";
	return 0;
}