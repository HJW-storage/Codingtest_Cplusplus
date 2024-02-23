// https://softeer.ai/practice/6289
// 소요시간 : 55분
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define max_n 100004
int n = 0, m = 0, p_cnt = 0, weight[max_n];
bool res[max_n];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 초기화
	fill(&res[0], &res[0] + max_n, true);

	cin >> n >> m;
	// 중량 입력.
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	// 친분관계 입력
	int n1 = 0, n2 = 0;
	for (int i = 1; i <= m; i++) {
		cin >> n1 >> n2;
		// res 결과 백터에 한번이라도 false 가 되면 이것은 false이다. 
		if (weight[n1] <= weight[n2]) res[n1] = false;
		if(weight[n1] >= weight[n2]) res[n2] = false;
	}

	// 사람 수 세기
	for (int i = 1; i <= n; i++) {
		if (res[i] == true) p_cnt++;
	}

	cout << p_cnt << "\n";
	return 0;
}