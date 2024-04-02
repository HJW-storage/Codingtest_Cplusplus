// https://www.acmicpc.net/problem/21608

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n = 0, grid[24][24] = { 0, };
const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

// vector<int> like_stu[24]; �̷��� �Ἥ ��� Ʋ�ȴ�... ������ <- ������ �� �о�� �л����� N^2 ���̴�.... 
vector<int> like_stu[404]; // �ε����� �л� ��ȣ�̸�, �����ϴ� �л��� ���������� �����Ѵ�.
vector<pair<pair<int, int>, pair<int, int>>> vec; // �ʱ�ȭ
int stu_idx = 0, tmp = 0;

bool cmp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b){
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			if (a.second.first == b.second.first) {
				return a.second.second < b.second.second;
			}
			return a.second.first < b.second.first;
		}
		return a.first.second > b.first.second;
	}
	return a.first.first > b.first.first;
}
void solve() {

	// (1,1)���� (n,n) ���� ������ ���� �����ϴ� �л��� �ִ��� �˻��ϰ�, 
	// {������ ĭ�� �����ϴ� �л��� ��, ������ ĭ�� ��ĭ�� ����, ��, ��} �� ���·� ���Ϳ� ����.
	vec.clear(); // �ʱ�ȭ

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (grid[r][c] > 0) continue;

			int next_row = 0, next_col = 0, cnt = 0, zero_cnt = 0; // �ʱ�ȭ
			for (int k = 0; k < 4; k++) {
				next_row = r + dr[k];
				next_col = c + dc[k];

				if (next_row < 1 || next_row > n || next_col < 1 || next_col > n) continue;
				if (grid[next_row][next_col] == 0) { // ������ ĭ�� ��ĭ�� ���.
					zero_cnt++;
				}

				for (int &it : like_stu[stu_idx]) {
					if (grid[next_row][next_col] == it) cnt++;
				}
			}

			vec.push_back({ {cnt, zero_cnt}, {r, c} });
		}
	}

	// ����
	sort(vec.begin(), vec.end(), cmp);

	// ���ĵ� ���� �Ǿ��� ��, ���� �л� ä���ֱ�
	
	grid[vec[0].second.first][vec[0].second.second] = stu_idx;

	return;
}

int cal_res() {
	int total_sum = 0;

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			int cur_student_idx = grid[r][c]; // ���� grid�� ��ġ�� �л��� ��ȣ.

			int next_row = 0, next_col = 0, cnt = 0; // �ʱ�ȭ
			for (int k = 0; k < 4; k++) {
				next_row = r + dr[k];
				next_col = c + dc[k];

				if (next_row < 1 || next_row > n || next_col < 1 || next_col > n) continue;
				
				for (int &it : like_stu[cur_student_idx]) {
					if (grid[next_row][next_col] == it) cnt++;
				}
			}

			if (cnt == 0) continue;
			else if (cnt == 1) total_sum += 1;
			else if (cnt == 2) total_sum += 10;
			else if (cnt == 3) total_sum += 100;
			else if (cnt == 4) total_sum += 1000;

		}
	}
	
	return total_sum;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n*n; i++) {
		cin >> stu_idx;
		for (int j = 1; j <= 4; j++) {
			cin >> tmp;
			like_stu[stu_idx].push_back(tmp);
		}
		solve();
	}

	cout << cal_res() << "\n";

	return 0;
}