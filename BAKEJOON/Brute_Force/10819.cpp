// https://www.acmicpc.net/problem/10819

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10] = { 0, }, n = 0, res = 0, cnt = 0;

void printV(vector<int>& tvec) {
	for (int it : tvec) cout << it << " ";
	cout << "\n";
}

void solve(vector<int>& tvec) {
	int t_size = tvec.size();
	int tmp_res = 0; // 초기화

	for (int i = 0; i < t_size-1;i++) {
		tmp_res += abs(arr[tvec[i]] - arr[tvec[i+1]]);
	}
	
	
	res = max(res, tmp_res);
	//cout << "tmp_res : " << tmp_res << "\n";
	return;
}
void make_permutation(int depth, vector<int> &vec) {

	if (depth == n) {
		//printV(vec);
		cnt++;
		// 로직 구현
		solve(vec);
		return;
	}

	for (int i = depth;  i < n; i++) {
		swap(vec[depth], vec[i]);
		make_permutation(depth + 1, vec);
		swap(vec[depth], vec[i]);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		v[i] = i; // 인덱스 채우기.
		cin >> arr[i];
	}
	
	make_permutation(0, v);
	cout << res << "\n";
	//cout << "cnt : " << cnt << "\n";
	return 0;
}