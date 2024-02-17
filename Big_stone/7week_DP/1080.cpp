// https://www.acmicpc.net/problem/1080

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, m = 0, grid_A[54][54] = { 0, }, grid_B[54][54] = { 0, }, res = 0;

void reverse_matrix3by3(int a, int b) {
	// 3x3 부분 행렬 원소 뒤집기. 
	for (int i = a; i <= a + 2; i++) {
		for (int j = b; j <= b + 2; j++) {
			grid_A[i][j] = 1 - grid_A[i][j];
		}
	}
	return;
}
void solve_greedy() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (grid_A[i][j] == grid_B[i][j]) continue;
			reverse_matrix3by3(i, j);
			res++;
		}
	}
	return;
}
bool compare_matrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid_A[i][j] != grid_B[i][j]) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	// 행렬 A 입력
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			grid_A[i][j] = tmp[j] - '0';
		}
	}
	// 행렬 B 입력
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			grid_B[i][j] = tmp[j] - '0';
		}
	}

	solve_greedy();
	// 결과 출력
	// res 초기값 = 0 으로 설정. 
	// 만약 행렬 A와 B가 같으면 true 반환하고 res 출력이므로 0을 출력. 
	if (compare_matrix()) {
		cout << res << "\n";
	}
	else {
		cout << "-1" << "\n";
	}

	return 0;
}

// 문제 이해 
// 행렬 뒤집기 연산은 3x3 씩으로만 뒤집기가 가능한 것이다.

// test-1 (뒤집기 연산 못하므로 a가 b가 될 수 없다. -1 출력.)
/*
	1 1
	1
	0
	answer : -1
*/

// test-2 (해당 경우에는 뒤집기 연산이 필요없다. a가 b가 이기에 0 출력. )
/*
	1 1
	1
	1
	answer : 0
*/