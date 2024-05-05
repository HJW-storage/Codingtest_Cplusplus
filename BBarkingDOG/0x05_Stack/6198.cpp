// https://www.acmicpc.net/problem/6198
// 자료형 확인 잘하자. 
// 빌딩의 개수는 80,000개 이다. 
// 만약, 빌딩이 80,000부터 ~ 1까지 내림차순으로 주어지면 총 res = 80,000 + 79,999 + ... + 1  ~= 80,001 * 40,000 = 3,200,040,000 (약 32억)
// 그렇기에 자료형은 long long이 되어야 한다!!!.

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;


#define max_hei_cnt 80004
int n = 0, building_hei[max_hei_cnt] = { 0, };
stack<int> stk;

ll calculate_buling_height() {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		while (stk.size() && stk.top() <= building_hei[i]) {
			stk.pop();
		}

		res += stk.size(); // 남아 있는 스택의 크기만큼 더해주기.
		stk.push(building_hei[i]); // 현재 높이 스택에 쌓기.
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> building_hei[i];
	}

	cout << calculate_buling_height() << "\n";
	return 0;
}