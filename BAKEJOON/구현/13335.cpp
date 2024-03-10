// https://www.acmicpc.net/problem/13335
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
using namespace std;

// n : 트럭의 수, w : 다리 길이, L : 최대 하중
int n = 0, w = 0, L = 0, truck_pass[1004] = { 0, }, truck_cnt = 0, truck_weight = 0, res_time = 0;
queue<pair<int, int>> q; // 다리를 통과하려고 기다리는 버스 대기열. 
deque<pair<int, int>> DQ; // 다리 위에 있는 버스들.

int main(void) {
	cin >> n >> w >> L;
	int weight = 0;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		q.push({ i, weight }); // {인덱스, 트럭 무게}
	}

	int idx = 0, wei = 0;
	while (q.size() != 0) {
		tie(idx, wei) = q.front();

		if ((truck_cnt + 1 <= w) && (truck_weight + wei <= L)) {
			truck_cnt += 1;
			truck_weight += wei;
			q.pop(); // 트럭 대기열에서 다리위로 올리는 의미.
			DQ.push_back({ idx, wei }); // 다리 위 트럭정보 덱에 저장.
		}

		for (pair<int, int> it : DQ) {
			truck_pass[it.first]++; // 다리 위 버스들이 시간에 따라 한칸씩 움직이는 것을 표시
			if (truck_pass[it.first] >= w) {
				DQ.pop_front();
				truck_cnt -= 1;
				truck_weight -= it.second;
			}
		}

		res_time++;
	}

	res_time = res_time + w;

	cout << res_time << "\n";
	return 0;
}