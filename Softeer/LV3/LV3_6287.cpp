// https://softeer.ai/practice/6287

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 1004
#define pos_a 0
#define pos_b 1

int n = 0, res[max_n][2] = { 0, };
pair<int, int> A[max_n], B[max_n]; // {작업시간, 이동시간}

int solve_dp() {
	// 기저사례
	res[1][0] = A[1].first; 
	res[1][1] = B[1].first;
	
	// 메모리제이션, 로직 구현
	for (int i = 2; i <= n; i++) {
		// pos_a로 오는 경우 : 2가지(a -> a,  b -> a)
		//						a -> a						b -> a					이동시간   +  작업시간
		res[i][pos_a] = min(res[i - 1][pos_a] + A[i].first, res[i - 1][pos_b] + (B[i-1].second + A[i].first));
		// pos_b로 오는 경우 : 2가지(b -> b,  a -> b)								
		//						b -> b						a -> b					이동시간   +  작업시간
		res[i][pos_b] = min(res[i - 1][pos_b] + B[i].first, res[i - 1][pos_a] + (A[i-1].second + B[i].first));
	}

	return min(res[n][pos_a], res[n][pos_b]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int ta = 0, tb = 0, a_to_b = 0, b_to_a = 0;
	for (int i = 1; i <= n - 1; i++) {
		cin >> ta >> tb >> a_to_b >> b_to_a;
		A[i] = { ta, a_to_b }; // {작업시간, 이동시간}
		B[i] = { tb, b_to_a }; // {작업시간, 이동시간}
	}
	cin >> ta >> tb; 
	A[n] = { ta, 0 }; // {작업시간, 이동시간} 마지막 작업하는 곳이므로 이동시간은 0으로 입력해준다.
	B[n] = { tb, 0 }; // {작업시간, 이동시간} 마지막 작업하는 곳이므로 이동시간은 0으로 입력해준다.

	cout << solve_dp() << "\n";
	return 0;
}