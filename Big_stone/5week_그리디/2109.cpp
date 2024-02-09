// https://www.acmicpc.net/problem/2109

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, d = 0, p = 0, res = 0, res1 = 0;
vector<pair<int, int>> schedule;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		schedule.push_back({ d, p });	// 입력 후에 sort 함수로 날짜 기준 정렬할 것이기에 날짜를 .first로 입력받는다.
	}

	// d를 기준으로 오름차순 정렬
	sort(schedule.begin(), schedule.end());


	// 로직 구현
	// 우선순위 큐를 이용한다.
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < n; i++) {
		pq.push(schedule[i].second);
		if (pq.size() > schedule[i].first) {
			pq.pop(); // 작은 값은 빼버리기
		}
	}
	while (pq.size()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << "\n";
	return 0;
}
/*
5
20 1
2 1
50 1
30 1
12 1
출력 : 50

5
10 1
20 2
30 3
40 4
50 5
출력 : 150

7
1 1
2 4
3 4
2 4
1 4
2 4
7 10000
결과값 : 16
현재 출력값 : 15


4
2 1 
4 1
8 2
100 2
결과값 : 108
현재 출력값 : 104
*/