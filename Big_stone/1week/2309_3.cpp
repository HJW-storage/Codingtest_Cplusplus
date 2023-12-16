// 순열을 이용한 풀이. 
// makePermutation 실제 정의해서 재귀호출로 풀이. 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 9;
int r = 7;
int cnt = 0;
vector<int> v_height;

void printV(vector<int>& tv) {
	for (int i = 0; i < r; i++) {
		cout << tv[i] << " ";
	}
	cout << "\n";
	cnt++;
	return;
}

void solve(vector<int> &hv) {
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		sum += hv[i];
	}
	if (sum == 100) {
		sort(hv.begin(), hv.begin() + 7);
		for (int i = 0; i < 7; i++) {
			cout << hv[i] << "\n";
		}
		exit(0);	// exit(0)은 해당 함수뿐 아니라 main 자체를 종료시키는 것이다. 
	}
}
void makePermutation(int n, int r, int depth) {
	// 기저사례
	if (depth == r) {
		//printV(v_height);
		solve(v_height);
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(v_height[i], v_height[depth]);
		makePermutation(n, r, depth + 1);
		swap(v_height[i], v_height[depth]);
	}
	return;
}
int main(void) {

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		v_height.push_back(temp);
	}

	makePermutation(n, r, 0);
	cout << cnt << endl;
}