// https://www.acmicpc.net/problem/14620
// 풀이시간 : 1시간 20분 (제외 조건에서 몇개씩 빼먹고 잘못 구현해서 시간 잡아먹음...) 
// 1. 완전탐색으로 가능 -> 조합 최대 combi(64,3)
// 2. 조합 조건에서 꽃이 죽는 조건은 제외
// 3. res 벡터에 비용을 저장하고 sort()정렬해서 최소구하기

// 다 풀고 생각해보니, 제외조건 대신에 방문처리로 해서 방문한 적이 있는곳에 방문하려고 하면
// 제외 조건이기에 제외시키면 더 쉽고 빠르게 구현이 될 것같다. 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0;
int cost[11][11];
vector<int> res;
// (1,1) ~ (n-2, n-2) 까지의 idx 정보 저장. <- 조합에서 뽑은 0 ~ (n-2*n-2) -1 인덱스에 매핑.
vector<pair<int, int>> grid_idx;
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

bool check_except(int a_row, int a_col, int b_row, int b_col) {
	// 제외해야하는 경우 -> 총 3가지 경우가 있다.
	// 열은 같고, 행의 차이가 2보다 작은 경우
	// 행은 같고, 열의 차이가 2보다 작은 경우 
	// 행과 열의 차이가 모두 1인 경우
	if ( (a_col == b_col && abs(a_row - b_row) <= 2) 
		|| (a_row == b_row && abs(a_col - b_col) <= 2)
		|| (abs(a_row - b_row) == 1 && abs(a_col - b_col) == 1)
		){
		return false;
	}
	return true;
}
bool except_combi(vector<int> &v) {
	// 크기는 3으로 고정이므로
	int first_row = grid_idx[v[0]].first;  int first_col = grid_idx[v[0]].second;
	int second_row = grid_idx[v[1]].first;  int second_col = grid_idx[v[1]].second;
	int third_row = grid_idx[v[2]].first;  int third_col = grid_idx[v[2]].second;
	
	bool first_flag = true, second_flag = true, third_flag = true;
	// 하나라도 false 이면 false를 반환한다. 
	first_flag = check_except(first_row, first_col, second_row, second_col);
	second_flag = check_except(second_row, second_col, third_row, third_col);
	third_flag = check_except(third_row, third_col, first_row, first_col);

	if (first_flag == false || second_flag == false || third_flag == false) {
		return false;
	}
	return true;
}
void combi(int start, int n, int r, vector<int> &v) {
	if (v.size() == r) {
		// 로직 구현
		// 꽃이 죽는 조건은 제외시킨다. 
		if (except_combi(v)) { // true 인 경우만 계산. 
			int tmp_cost = 0;
			for (int i = 0; i < r; i++) {
				int cur_row = grid_idx[v[i]].first;
				int cur_col = grid_idx[v[i]].second;
				tmp_cost += cost[cur_row][cur_col];
				for (int i = 0; i < 4; i++) {
					int next_row = cur_row + dr[i];
					int next_col = cur_col + dc[i];
					// 인덱스 벗어나는 경우가 없기에 따로 검사안해도 된다.
					tmp_cost += cost[next_row][next_col];
				}
			}
			res.push_back(tmp_cost);
		}
		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, n, r, v);
		v.pop_back();
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
			if ((i >= 1 && i <= n - 2) && (j >= 1 && j <= n - 2)) {
				grid_idx.push_back({i, j});
			}
		}
	}

	int combi_n = (n - 2) * (n - 2);
	vector<int> b;
	combi(-1, combi_n, 3, b);
	sort(res.begin(), res.end());
	cout << res[0] << "\n";

	return 0;
}
