// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int k = 0, node_n = 0;
int arr[1030];
vector<int> res[11];

void go(int start, int end, int level) {
	if (start > end) return;
	if (start == end) {
		res[level].push_back(arr[start]);
		return;
	}

	int mid = (start + end) / 2;
	res[level].push_back(arr[mid]);
	go(start, mid - 1, level+1);
	go(mid + 1, end, level+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	node_n = (int)pow(2, k) - 1;

	for (int i = 0; i < node_n; i++) {
		cin >> arr[i];
	}

	go(0, node_n, 0);
	for (int i = 0; i < k; i++) {
		for (auto it : res[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}