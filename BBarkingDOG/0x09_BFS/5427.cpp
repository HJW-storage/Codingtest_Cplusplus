// https://www.acmicpc.net/problem/5427
// 102��° ��, ť �ʱ�ȭ�� ���, ��� ������ߴ�..... ť�� �ʱ�ȭ ������ϴ°� �������ƾ��Ѵ�..
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
#define max_n 1004

char grid[max_n][max_n];
int test_case = 0, w = 0, h = 0, visited[max_n][max_n] = { 0, };
const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> fire_q;

void Qclear(queue<pair<int, int>>& _q) {
	queue<pair<int, int>> empty_q;
	swap(_q, empty_q);
}

void Spread_Fire() {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	queue<pair<int, int>> t_q;
	while (fire_q.size()) {
		tie(cur_row, cur_col) = fire_q.front();
		fire_q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= h || next_col < 0 || next_col >= w) continue;
			if (grid[next_row][next_col] != '*' && grid[next_row][next_col] != '#') {
				grid[next_row][next_col] = '*'; // ���� ������.
				t_q.push({ next_row, next_col });
			}
		}
	}
	swap(fire_q, t_q);
	return;
}

// �ʱ� ��ġ�� ���� ���� �� �ִ� �����̴�!! 
void solve_bfs(int &s_row, int &s_col) {
	// �ʱ� �湮ó��
	visited[s_row][s_col] = 1; 
	queue<pair<int, int>> q; // {��, ��}
	q.push({ s_row, s_col });

	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	int earliest_time = 0;
	bool escape = false;

	while(1){
		Spread_Fire(); // �� ���� ������
		
		if (q.size() == 0) break;
		queue<pair<int, int>> tmp_pos;

		while (q.size()) {
			tie(cur_row, cur_col) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];

				// �ε����� ����� Ż���� �� ���̴�.
				if (next_row < 0 || next_row >= h || next_col < 0 || next_col >= w) {
					escape = true; // Ż�� ����.
					earliest_time = visited[cur_row][cur_col];
					break;
				}

				if (visited[next_row][next_col] > 0) continue; // �̹� �湮 �ߴ� ��.
				if (grid[next_row][next_col] != '*' && grid[next_row][next_col] != '#') {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1; // �湮ó��.
					tmp_pos.push({ next_row, next_col });
				}
			}
			if (escape) break; // Ż�� ����
		}
		if (escape) break; // Ż�� ����
		swap(q, tmp_pos);
	}

	if (escape) cout << earliest_time << "\n";
	else cout << "IMPOSSIBLE" << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> test_case;
	while (test_case--) {
		// test_case ���� �ʱ�ȭ
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
		fill(&grid[0][0], &grid[0][0] + max_n * max_n, 'a');
		Qclear(fire_q);

		cin >> w >> h; // w : col, h : row
		int s_row = 0, s_col = 0;
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				cin >> grid[r][c];
				if (grid[r][c] == '@') {
					s_row = r;
					s_col = c;
				}
				else if (grid[r][c] == '*') fire_q.push({ r, c });
			}
		}

		solve_bfs(s_row, s_col); // Ż�� �õ�.
	}

	return 0;
}

/*
TC-1
<input>
1
4 3
####
#*@.
####
<output>
2

TC-2
<input>
1
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
<output>
5

TC-3
<input>
1
7 4
###.###
#....*#
#@....#
.######
<output>
IMPOSSIBLE

TC-4
<input>
1
5 5
.....
.***.
.*@*.
.***.
.....
<output>
IMPOSSIBLE

TC-5
<input>
1
3 3
###
#@#
###
<output>
IMPOSSIBLE

TC-6
<input>
1
1 1
@
<output>
1

TC-7
<input>
1
2 1
@*
<output>
1

TC-8
<input>
1
3 1
#@*
<output>
1

TC-9
<input>
1
3 4
...
.*.
*@*
..*
<output>
IMPOSSIBLE

TC-10
<input>
1

10 5

##########
#@....#*.#

#.....#..#

#.....#..#

##.#######
<output>
5
*/