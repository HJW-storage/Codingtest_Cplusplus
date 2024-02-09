// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, k = 0, boseok_weight = 0, boseok_price = 0, bag_weight = 0;
ll res = 0;
vector<pair<int, int>> boseok;
vector<int> bag;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// 입력 받기
	cin >> n >> k;
	// 다음 n 줄에 걸쳐서 보석 무게와 가격이 입력
	for (int i = 0; i < n; i++) {
		cin >> boseok_weight >> boseok_price;
		// 보석 무게 기준으로 이후에 정렬할 것이기에 {무게, 가격} 순으로 저장.
		boseok.push_back({ boseok_weight, boseok_price });
	}
	// 다음 k줄에 걸쳐서 가방이 담을 수 있는 최대 무게가 주어진다.
	for (int i = 0; i < k; i++) {
		cin >> bag_weight;
		bag.push_back(bag_weight);
	}

	// sort 정렬 -> O(nlogn) 
	
	// 보석은 무게를 기준으로 오름차순 정렬이면서, 같은 무게일 때는 가격을 기준으로 오름차순 이다.
	// 그냥 sort 함수 기본을 써도 만족된다. 
	sort(boseok.begin(), boseok.end()); 

	// 보석 가방 허용 무게를 기준으로 오츰차순 정렬한다.
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;	// 우선수위 큐 -> 큰 수서대로 앞쪽으로 자동 정렬된다.

	// 정렬한 보석 무게와 가격을 기준으로 로직 구현. 
	int boseok_idx = 0;
	for (int i = 0; i < k; i++) {
		while (boseok_idx < n && boseok[boseok_idx].first <= bag[i]) {
			pq.push(boseok[boseok_idx].second);
			boseok_idx++;
		}
		if (pq.size()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << "\n";

	return 0;
}

/*
1 1
1 65
2
*/
