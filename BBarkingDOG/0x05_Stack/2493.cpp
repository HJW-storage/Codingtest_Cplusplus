// https://www.acmicpc.net/problem/2493
// ������ ���� N���� ���̰� ���� �ٸ� ž. 
// ���� ������ ž�� ����. 

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define hei_max 500'004

int n = 0, top_hei[hei_max] = { 0, }, res[hei_max] = { 0, };
stack<pair<int, int>> stk; // {����, �ε���}

void solve_stack() {
	for (int i = 1; i <= n; i++) {
		while (stk.size() && stk.top().first <= top_hei[i]) {
			stk.pop();
		}
		
		if (stk.size()) res[i] = stk.top().second;
		else res[i] = 0;

		stk.push(make_pair(top_hei[i], i)); // ���� {����, �ε���} ���ÿ� �־��ֱ�.
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> top_hei[i];
	}

	solve_stack();
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
TC-1 
<input>
5
1 2 3 4 5
<output>
0 0 0 0 0

<input>
5
5 4 3 2 1
<output>
0 1 2 3 4
*/