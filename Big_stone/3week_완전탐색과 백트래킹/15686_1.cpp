// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0, m = 0, temp = 0, res = 1000000;
vector<pair<int, int>> house_idx;
vector<pair<int, int>> chicken_idx;

int measure_mindis(int row1, int col1, vector<int>& b) {
	int mindis = 100000;
	for (int chicken_it : b) {
		int row2 = chicken_idx[chicken_it].first;
		int col2 = chicken_idx[chicken_it].second;
		mindis = min(mindis, abs(row2 - row1) + abs(col2 - col1));	// 가장 최소거리를 반환.
		if (mindis == 1) return 1;	// 백트래킹. 최소 거리는 1이므로 1이 나왔다면 탈출.
	}
	return mindis;
}

// 조합 구현
void combi(int start, int chicken_n, int r, vector<int>& b) {
	if (b.size() == r) {
		// 로직 구현
		// 집 하나를 기준으로 치킨집들의 거리 중 최소 거리를 구한다.
		int dis = 0;
		for (pair<int, int> house_it : house_idx) {
			dis += measure_mindis(house_it.first, house_it.second, b);
		}

		// 최소 값을 구해야하기에 가장 작은 수를 저장한다. 
		res = min(res, dis);
		return;
	}

	for (int i = start + 1; i < chicken_n; i++) {
		b.push_back(i);
		combi(i, chicken_n, r, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 좌표 계산 편하려고 1부터 시작.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 2) {
				chicken_idx.push_back({ i, j });
			}
			else if (temp == 1) {
				house_idx.push_back({ i, j });
			}
			else { ; }
		}
	}

	int chicken_n = chicken_idx.size();
	vector<int> v;
	combi(-1, chicken_n, m, v);
	cout << res << "\n";
	return 0;
}