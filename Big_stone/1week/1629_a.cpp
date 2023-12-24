// https://www.acmicpc.net/problem/1629
// 시간초과를 줄이는 것
// 모듈려 연산의 특성을 활용하여 풀이. 

#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;
ll a, b, c;

ll solve(ll a, ll b) {
	if (b == 1) {
		return a % c;
	}
	ll result = solve(a, b / 2);
	result = (result * result) % c;
	
	// 홀수인 경우는 맨 처음 b/2 재귀하면서 한번이 날라갔기에 추가로 한번 곱해서 나누는 과정을 추가한다.
	if (b % 2 != 0) {
		result = (result * a) % c;
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	cout << solve(a, b) << "\n";

	return 0;
}