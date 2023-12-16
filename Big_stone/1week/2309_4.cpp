#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 9;
int r = 7;
vector<int> height(n, 0);

void printV(vector<int>& v) {
	for (auto it : v) cout << it << " ";
	cout << "\n";
}

void solve(vector<int>& v) {
	int sum = 0;
	for (auto it : v) {
		sum += height[it];
	}
	if (sum == 100) {
		vector<int> c_height;
		for (int i : v) {
			c_height.push_back(height[i]);
		}
		sort(c_height.begin(), c_height.end());
		for (int it : c_height) cout << it << "\n";
		exit(0);
	}
}
void combi(int start, vector<int>& v) {
	if (v.size() == r) {
		//printV(v);
		solve(v);
		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main() {
	vector<int> b;

	// 9난쟁이 키 입력받기
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	combi(-1, b);


	return 0;
}