// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;
map<int, int> mp_first;
vector<pair<int, int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return mp_first[a.first] < mp_first[b.first];
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n = 0, c = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int in_tmp;
		cin >> in_tmp;

		// 1순위 기준을 위한 map
		if (!mp[in_tmp]) {	// mp[in_tmp] <if 조건으로 비교하기 위해 참조를 한 것이다. map은 참조만 하더라도 기본값으로 초기화 된다.> int의 경우 0으로
			mp[in_tmp] = 1;
		}
		else {
			mp[in_tmp]++;
		}

		// 2순의 기준을 위한 map (규칙 : 먼저 나온 것은 먼저 출력 -> mp_first에 먼저 나온것의 value가 더 적은값이 저장된다.)
		if (mp_first[in_tmp] == 0) {
			mp_first[in_tmp] = i + 1; // +1 을 해주는 것은 : i가 0부터 시작인데 케이스에 0부터 고려해야 하는 경우가 있을 수 있기에 +1을 해준다.
		}
	}

	// map에 있는 것을 vector로 복사.
	for (auto& it : mp) {
		vec.push_back(it);
	}

	// cmp에서 정의한 기준으로 정렬 수행.
	sort(vec.begin(), vec.end(), cmp);

	// 출력
	for (auto& it : vec) {
		for (int i = 0; i < it.second; i++) {
			cout << it.first << " ";
		}
		//cout << " key : " << it.first << " value : " << it.second << "\n";
	}

	
	return 0;
}