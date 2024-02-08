// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 해당 문제의 가장 쉬운 풀이는 배열을 하나 선언해서 그어진 선에 1을 표시하는 것이나
// 10억개의 배열은 메모리 초과이므로 다른 방법 고안.

// 시작 위치를 기준으로 정렬해서 선을 그어나가며 끝 위치를 갱신.
// 중간에 끊기는 부분이 생기면. 시작위치를 그다음 위치로 갱신하고 끝 위치도 갱신. 
vector<pair<int, int>> pos_v;
int n = 0, start_pos = 0, end_pos = 0, res = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int tmp_start = 0, tmp_end = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp_start >> tmp_end;
		pos_v.push_back({ tmp_start, tmp_end });
	}

	// 시작 위치를 기준으로 오름차순 정렬
	sort(pos_v.begin(), pos_v.end());
	start_pos = pos_v[0].first;
	end_pos = pos_v[0].second;
	for (int i = 1; i < n; i++) {
		if (pos_v[i].first <= end_pos) {
			if (end_pos >= pos_v[i].second) continue;
			end_pos = pos_v[i].second; // 끝 지점 갱신
		}
		else if (pos_v[i].first > end_pos) {
			res += end_pos - start_pos;
			// 시작과 끝 갱신
			start_pos = pos_v[i].first;
			end_pos = pos_v[i].second;
		}
	}
	res += end_pos - start_pos;
	cout << res << "\n";
	return 0;
}