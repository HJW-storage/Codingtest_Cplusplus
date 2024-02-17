// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, Eratos[4'000'004] = { 0, }, res = 0;
vector<int> eratos_v;

void consist_Eratos() {
	// 각 인덱스에 해당하는 값을 채워두고, 
	for (int i = 1; i <= n; i++) {
		Eratos[i] = i;
	}

	// 소수가 아닌것을 지우는 것을 = 0 으로 넣어서 표시.
	for (int i = 2; i <= n; i++) {
		if (Eratos[i] == 0) continue;
		for (int j = i; j <= n; j += i) {
			if (i == j) continue;
			if (Eratos[j] == 0) continue;
			Eratos[j] = 0;
		}
	}

	// 소수만 추려낸 벡터 구성. 
	for (int i = 2; i <= n; i++) {
		if (Eratos[i] == 0) continue;
		eratos_v.push_back(Eratos[i]);
	}

	return;
}

int solve_wayscnt() {
	int way_cnt = 0;
	int sum = 0;

	// 연속된 소수의 합으로 표현하기
	int v_size = eratos_v.size();
	queue<int> q;
	for (int i = 0; i < v_size;) {
		if (sum < n) {
			sum += eratos_v[i];
			q.push(eratos_v[i]);
			i++;
		}
		else if (sum > n) {
			while (sum > n) { // sum <= n 으로 만들어야 한다.
				if (q.size()) {
					sum -= q.front();
					q.pop();
				}
			}
		}
		//cout << "sum : " << sum << "\n";

		if (sum == n) {
			//cout << "조건 달성!! -> sum : " << sum << "\n\n";
			way_cnt++;
			// 그 다음 반복문에서 다음 수 더해야 하니까 한번 빼준다. 
			if (q.size()) {
				sum -= q.front();
				q.pop();
			}
		}
	}

	// 추가 예외 (끝 조건에는 while 문이 걸리지 않는다.)
	if (eratos_v[v_size - 1] == n) way_cnt++;

	// 예외처리 (n == 2) 일 때만 위의 작성한 알고리즘 way_cnt가 1이 더 추가되기에
	// 간단히 n == 2 일때만 예외처리로 해주자. 
	if (n == 2) way_cnt = 1;
	return way_cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	consist_Eratos();
	//for (int it : eratos_v) cout << it << " ";

	if (n == 1) cout << "0" << "\n";
	else cout << solve_wayscnt() << "\n";

	return 0;
}