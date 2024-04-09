// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n = 0, m = 0, grid[54][54] = { 0, }, visited[54][54] = { 0, }, res = 0;
int start_row = 0, start_col = 0, start_dir = 0;
// "0" : ����,
// "1" : ����, 
// "2" : ����, 
// "3" : ����
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void Q_Clear(queue<tuple<int, int, int>> &tq) {
	queue<tuple<int, int, int>> empty_q;
	swap(tq, empty_q);
	return;
}

void solve_bfs(int row, int col, int dir) {
	visited[row][col] = 1; // �湮ó�� - û�ҿϷ�
	res += 1;

	queue<tuple<int, int, int>> q;
	q.push({ row, col, dir });

	queue<tuple<int, int, int>> tmp_Q;

	int cur_row = 0, cur_col = 0, cur_dir = 0, next_row = 0, next_col = 0, next_dir = 0;
	while (q.size()) {
		tie(cur_row, cur_col, cur_dir) = q.front();
		q.pop();

		int tmp_dir = cur_dir;
		// �ֺ� 4ĭ û�ҵ��� ���� ��ĭ�� �ִ��� �˻��Ѵ�.
		for (int i = 0; i < 4; i++) { // 4���� �����µ�, ���� �ٶ󺸰� �ִ� ������ �������� �ݽð� �������� ������.
			
			/*
			next_dir = tmp_dir--;  �̷��� �Ἥ ����� �� �����ߴ�...  ���� ������ ���� �ٿ��� -- �Ǵ°��̴�...
			next_dir = --tmp_dir;  ���� ������ ���� -- �ϰ� ����.
			*/
			next_dir = --tmp_dir; 
			if (next_dir < 0) next_dir += 4;

			next_row = cur_row + dr[next_dir];
			next_col = cur_col + dc[next_dir];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == 0) {
				tmp_Q.push({ next_row, next_col, next_dir });
			}

		}

		// û���� ĭ�� �ִ��� tmp_Q ũ�⸦ ���� �� �� �ִ�.
		if (tmp_Q.size()) {
			// ���� dir�� �������� �ݽð�� �˻��߱⿡ ���� �տ� �ִ°��� û���Ѵ�.
			tie(next_row, next_col, next_dir) = tmp_Q.front();
			visited[next_row][next_col] = 1; // �湮ó�� = û��
			res++;
			q.push({ next_row, next_col, next_dir }); // ���� ť �湮���� ��ġ push.
			Q_Clear(tmp_Q); // ť ����.
		}
		// û���� ĭ�� ���� ���� 
		else {
			// ���� ������ä�� ����. -> �̵��� �ݴ� �������� �ϴ� ���̴�.
			
			int move_dir = (cur_dir - 2 < 0 ? cur_dir - 2 + 4 : cur_dir - 2);
			next_row = cur_row + dr[move_dir];
			next_col = cur_col + dc[move_dir];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) break;
			if (grid[next_row][next_col] == 0) {
				q.push({ next_row, next_col, cur_dir }); // ������ ���� ������ �־��ش�.
			}
			else {
				break;
			}
		}

	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	cin >> start_row >> start_col >> start_dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	solve_bfs(start_row, start_col, start_dir);
	cout << res << "\n";
	
	return 0;
}