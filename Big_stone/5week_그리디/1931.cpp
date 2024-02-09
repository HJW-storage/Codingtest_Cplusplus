// https://www.acmicpc.net/problem/1931
// 그리디 문제.. 정렬을 활용하여 최적의 해를 찾음. 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int n = 0, res = 0;
int check_arr[100004];
ll start_t = 0, end_t = 0;
vector<pair<int, int>> time_schedule;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start_t >> end_t;
		// 종료 시간을 기준으로 먼저 입력 받고. 
		// 나중에 sort 함수를 하면 기본적으로 첫번쨰 pair 값으로 정렬한다.
		time_schedule.push_back({ end_t, start_t }); 
	}

	sort(time_schedule.begin(), time_schedule.end());
	
	// 로직 구현
	ll prev_end_time = -1;
	for (pair<int, int> it : time_schedule) {
		// pair<int ,int> => {end_time, start_time} 의 형식으로 저장됨. 
		if (prev_end_time <= it.second) {
			
			//중복해서 회의가 있더라도 둘다 동시에 진행된다고 가정하는 것이 이상하지만 이렇게 해야 맞습니다가 나오네요!
			/*
			3
			4 4
			4 4
			1 4
			기댓값 : 3
			*/
			res++;
			prev_end_time = it.first;
		}
	}

	cout << res << "\n";
	return 0;
}