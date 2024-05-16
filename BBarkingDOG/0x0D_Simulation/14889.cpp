// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n = 0, grid[24][24] = { 0, }, cmp_res = 0;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> start_team(24, 0), link_team(24, 0), cmp_vec(24, 0);

void build_team(vector<int>& tv, int v_size) {
	for (int i = 0; i < v_size; i++) {
		start_team[i] = tv[i];
		cmp_vec[tv[i]] = 1;
	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (cmp_vec[i] ^ 1) link_team[idx++] = i;
	}

	return;
}

int cal_team_score(int _size) {
	int start_team_sco = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			start_team_sco += grid[start_team[i]][start_team[j]];
		}
	}

	int link_team_sco = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			link_team_sco += grid[link_team[i]][link_team[j]];
		}
	}
	return abs(start_team_sco - link_team_sco);
}
void combi_1(vector<int> &v, int start) {
	if (v.size() == int(n / 2)) {
		// 초기화
		for (int i = 0; i < n; i++) {
			cmp_vec[i] = 0;
		}

		// 팀 나누기
		build_team(v, v.size());

		/*cout << "\n";
		cout << "팀나누기 진행.\n";
		cout << "스사팀 : ";
		for (int i = 0; i<int(n / 2); i++) cout << start_team[i] << " ";
		cout << "\n";
		cout << "링크팀 : ";
		for (int i = 0; i<int(n / 2); i++) cout << link_team[i] << " ";
		cout << "\n";*/

		// 팀 별 능력치 계산하기.
		cmp_res = cal_team_score(int(n / 2));
		if (pq.size()) {
			if (cmp_res < pq.top()) pq.push(cmp_res);
		}
		else {
			pq.push(cmp_res);
		}
		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi_1(v, i);
		v.pop_back();
	}
	return;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for(int i=0;i<n;i++){
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	vector<int> tmp_v;
	combi_1(tmp_v, -1);

	cout << pq.top() << "\n";
	return 0;
}