#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0, k = 0;
int num_max = -(1e7 + 1); // 문제 조건을 잘보고 가장 최저인 값보다 더 작은값을 설정해줘야한다. 

// 최대값을 찾는 문제는 기준을 잡는 값을 최악의 상황보다 더 작은 최솟값에서 시작하여 max()함수를 통해 비교하며
// 답을 찾아간다. 

int main() {
	cin >> n >> k;
	vector<int> numv(n+1, 0);	// 정수 입력 백터
	vector<int> sumv(n + 1, 0);	// 구간합 저장 백터
	vector<int> ksumv(n + 1, 0); // k일 연속 날짜 합 저장 벡터

	for (int i = 1; i <= n; i++) {
		cin >> numv[i];
		sumv[i] = numv[i] + sumv[i - 1];	// 구간합 구하기
	}

	for (int i = k; i <= n; i++) {
		ksumv[i] = sumv[i] - sumv[i - k];
		num_max = max(num_max, ksumv[i]);
	}

	cout << num_max << "\n";

	return 0;
}