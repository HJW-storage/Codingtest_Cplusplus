// https://www.acmicpc.net/problem/1992
#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
char grid[65][65];

string solve(int row, int col, int size) {
	// 기저 조건
	if (size == 1) { return string(1, grid[row][col]); }
	string res = "";
	char b = grid[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (grid[i][j] != b) {
				res += "(";
				res += solve(row, col, size / 2);
				res += solve(row, col + size / 2, size / 2);
				res += solve(row + size / 2, col, size / 2);
				res += solve(row + size / 2, col + size / 2, size / 2);
				res += ")";
				return res;
			}
		}
	}
	return string(1, grid[row][col]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			grid[i][j] = temp[j];
		}
	}

	string result = solve(0, 0, n);
	cout << result << "\n";
	return 0;
}