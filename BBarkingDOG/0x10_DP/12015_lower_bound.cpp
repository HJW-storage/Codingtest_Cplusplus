// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
vector<int> res_vec;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (res_vec.size() == 0 || *(res_vec.end()-1) < tmp) {
			res_vec.push_back(tmp);
		}
		else {
			*(lower_bound(res_vec.begin(), res_vec.end(), tmp)) = tmp;
		}
	}
	cout << res_vec.size() << "\n";
	return 0;
}