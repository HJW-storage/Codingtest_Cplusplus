#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int n = 3;
int a[3][3] = {
		{10, 20, 21},
		{70, 90, 12},
		{80, 110, 120}
};
int visited[3][3];
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };
vector<int> v;

void printV(vector<int> &v) {
	for (int it : v) cout << it << " ";
	cout << "\n";
	return;
}
void go(int row, int col) {
	if (row == n - 1 && col == n - 1) {
		printV(v);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
			if (visited[next_row][next_col] == 0) {
				visited[next_row][next_col] = 1;	// 规巩
				v.push_back(a[row][col]);

				go(next_row, next_col);

				visited[next_row][next_col] = 0;	// 规巩 秦力
				v.pop_back();
			}
		}
	}
	return;
}
int main() {
	visited[0][0] = 1; // 规巩贸府
	v.push_back(a[0][0]);
	go(0, 0);
	return 0;
}

