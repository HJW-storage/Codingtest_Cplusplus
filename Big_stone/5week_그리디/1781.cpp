// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, deadline = 0, noodle_cnt = 0, res = 0;
vector<pair<int, int>> V;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		// 입력 : 기간, 가격
		cin >> deadline >> noodle_cnt;
		V.push_back({ deadline, noodle_cnt });
	}

	// 기간을 기준으로 오름차순 정렬
	sort(V.begin(), V.end());

	// 최대값을 구한다. 
	// 우선순위 큐를 활용하여 최소(작은 값)를 제외하며 큐에는 최대를 구성할 수 있는 값만 남긴다.
	priority_queue<int, vector<int>, greater<int>> pq; // 작은 값이 맨 앞을 정렬.
	int dl = 1;
	int i = 0;
	while (1) {
		while (i < n && V[i].first <= dl) {
			pq.push(V[i].second);
			i++;
		}
		// 큐에 있는 원소가 데드라인 개수보다 많으면 데드라인 개수까지 최소의 값들을 제거한다.
		if (pq.size() > dl) {
			while (pq.size() != dl) {
				pq.pop(); // 작은 값은 제외시킨다. 
			}
		}
		if (i >= n) break; // 탈출 조건.
		dl = V[i].first; // 다음 기한 값으로 update. 
	}
	
	//// 위 while문을 아래의 for문으로 간단하게 처리할 수 있다. 
	//// sort 정렬을 했기에 많은 복잡한 조건이 추가할 필요가 없음.  
	//for (int i = 0; i < n; i++) {
	//	pq.push(V[i].second);
	//	if (pq.size() > V[i].first) {
	//		pq.pop();
	//	}
	//}
	
	// 최댓값 구하기.
	while (pq.size()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << "\n";
	return 0;
}