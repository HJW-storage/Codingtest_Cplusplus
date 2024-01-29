// https://www.acmicpc.net/problem/3273

// 1. 오름차순 정렬
// 2. 투포인터

#include <iostream>
#include <algorithm>
#include <vector>
#define max_n 1000004
using namespace std;
int n = 0, x= 0, result = 0;

void two_pointer_search(int start, int end, vector<int> &num_arr) {
	while (start < end) {
		int sum = num_arr[start] + num_arr[end];
		if (sum == x) {
			result++;
			start++;
		}
		else if (sum < x) {
			start++;
		}
		else if (sum > x) {
			end--;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> num_arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num_arr[i];
	}
	cin >> x;

	// 2. 투포인터
	// 1. 오름차순 정렬
	sort(num_arr.begin(), num_arr.end());
	two_pointer_search(0, n - 1, num_arr);

	cout << result << "\n";
	return 0;
}