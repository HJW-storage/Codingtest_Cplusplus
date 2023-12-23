// https://www.acmicpc.net/problem/9375

// 전형적인 여사건으로 풀이해야 쉬운 문제. 
// 모자 : a, b  -> a, b, 안입음 (2+1 가지)
// 하의 : c, d  -> c, d, 안입음	(2+1 가지)
// 상의 : e, f, g	-> e, f, g, 안입음	(3+1 가지)
// -> 경우의 수는 = ((2+1) * (2+1) * (3+1)) - 1   (모두 안입는 경우는 제외. 여사건의 경우) 
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long ll;

using namespace std;
int test = 0, n = 0;
string cloth_name, cloth_kind;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		map<string, int> cloth; // 테스트 케이스마다 map이 초기하 되어야 함로.
		for (int j = 0; j < n; j++) {
			cin >> cloth_name >> cloth_kind;
			if (cloth[cloth_kind]) {
				cloth[cloth_kind]++;
			}
			else {
				cloth[cloth_kind] = 1;
			}
		}

		ll result_case = 1;
		for (auto pair : cloth) {
			result_case *= (ll(pair.second) + 1);
		}
		
		result_case = result_case - 1; // 여사건으로 1을 빼준다.
		cout << result_case << "\n";
	}

	return 0;
}