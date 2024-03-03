// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define max_n 1'000'004
int n = 0, arr[max_n] = { 0, };
vector<int> res;

int bisearch(int val) {
	// 시작을 0으로 <- res 벡터도 인덱스 0부터 이므로.
	int first = 0;
	int last = res.size() - 1;
	
	// lower_bound 이기에 last를 return
	// 만약, upper_bound 였다면 first를 return한다. 
	while (first < last) {
		int mid = (first + last) / 2;
		if (res[mid] >= val) {
			last = mid;
		}
		else {
			first = mid + 1;
		}
	}
	return last;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	res.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > res.back()) {
			res.push_back(arr[i]);
		}
		else {
			int idx = bisearch(arr[i]);
			res[idx] = arr[i];
		}
	}
	cout << res.size() << "\n";
	return 0;
}