// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

ll n = 0, k = 0, boseok_weight = 0, boseok_price = 0, bag_weight = 0, res = 0;
vector<pair<ll, ll>> boseok;
vector<int> bag;
queue<int> price;
stack<int> bag_price_stk;

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

	// 정렬한 보석 무게와 가격을 기준으로 로직 구현. 
	ll bag_idx = 0;
	ll stack_tp = 0;
	for(int i=0;i<n;i++){
		// 오름차순으로 탐색하며 첫번째 가방의 최대 무게 이하인 곳의 보석의 최대 무게를 결과값에 더한다.
		// 이때, stack 을 사용해서 이전 값보다 가격이 비싼 경우에만 stack에 넣는다. 
		// stack 을 활용하여 하면, 이전 가방을 채우고 난뒤, 두번쨰로 비싼 보석의 가격을 알 수 있다.
		if (bag_price_stk.size() == 0) {
			stack_tp = 0;
		}
		else if (bag_price_stk.size() > 0) {
			stack_tp = bag_price_stk.top();
		}

		if (bag_idx == k) break;
		// {무게, 가격}
		if (boseok[i].first < bag[bag_idx]) {
			// 무게도 만족하며 가격이 이전 stack 최상위 보다 비싸면 stack에 추가. 
			if (stack_tp < boseok[i].second) bag_price_stk.push(boseok[i].second);
		}
		else if(boseok[i].first == bag[bag_idx]) {
			if (boseok[i].second >= stack_tp) {
				res += boseok[i].second;
			}
			else {
				res += stack_tp; // stack 맨 위에 최대 가격 더해주고 
				if (bag_price_stk.size()) bag_price_stk.pop(); // 맨 위 스택값 제외해주기. 
				if(bag_price_stk.size() && bag_price_stk.top() < boseok[i].second) bag_price_stk.push(boseok[i].second);
			}
			bag_idx++;
		}
		else if (boseok[i].first > bag[bag_idx]) {
			res += stack_tp; // stack 맨 위에 최대 가격 더해주고 
			if(bag_price_stk.size()) bag_price_stk.pop(); // 맨 위 스택값 제외해주기. 
			if (bag_price_stk.size() && bag_price_stk.top() < boseok[i].second) bag_price_stk.push(boseok[i].second);
			
			bag_idx++;
		}

	}
	
	if (bag_idx != k) {
		res += stack_tp;
	}
	if (res == 0 && bag_price_stk.size()) {
		res += bag_price_stk.top();
	}
	cout << res << "\n";
	return 0;
}
/*
2 1
6 6
6 6
5

1 1
1 65
2
*/