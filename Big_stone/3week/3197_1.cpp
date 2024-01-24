//https://www.acmicpc.net/problem/3197

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define max_n 1504

using namespace std;
int n = 0, m = 0;
char grid[max_n][max_n];
int visited_water[max_n][max_n];
int visited_bbakjo[max_n][max_n];
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> bbakjo;
queue<pair<int, int>> bbakjo_q, bbakjo_tmpq;
queue<pair<int, int>> water_q, water_tmpq;

// ť ����
void Qclear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> emptyq;
	swap(q, emptyq);
}
// ���� ���̱� (grid[][] ���� �����Ų��.)
void melting() {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (water_q.size()) {
		cur_row = water_q.front().first;
		cur_col = water_q.front().second;
		water_q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (visited_water[next_row][next_col] == 0 && grid[next_row][next_col] == 'X') {
					visited_water[next_row][next_col] = 1; // �湮 ó��
					grid[next_row][next_col] = '.'; // ���� ���̱�. 
					water_tmpq.push({ next_row, next_col });
				}
			}
		}
	}

	// tmpq �������ֱ�
	water_q = water_tmpq;
	Qclear(water_tmpq);	// ť ����
	return;
}
// ������ �������� �˻� (grid[][] ���� �����Ű�� �ʰ� �˻縸�Ѵ�.)
bool bbakjo_meet(int end_row, int end_col) {
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while (bbakjo_q.size()) {
		cur_row = bbakjo_q.front().first;
		cur_col = bbakjo_q.front().second;
		bbakjo_q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			
			// �˻� (���� ������ Ż��)
			if (next_row == end_row && next_col == end_col) {
				return true;
			}

			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (visited_bbakjo[next_row][next_col] == 0) {
					if (grid[next_row][next_col] == '.') {
						bbakjo_q.push({ next_row, next_col }); // ���� ���� ��������.
						visited_bbakjo[next_row][next_col] = 1; // �湮ó��
					}
					else if (grid[next_row][next_col] == 'X') {
						bbakjo_tmpq.push({ next_row, next_col }); // ���� ���� Ž�� ��ġ �߰�
						visited_bbakjo[next_row][next_col] = 1; // �湮ó��
					}

				}
			}
		}
	}
	// tmpq �������ֱ�
	bbakjo_q = bbakjo_tmpq;
	Qclear(bbakjo_tmpq);	// ť ����
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ��ĭ ���� �ԷµǴ� ���ڿ�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if (grid[i][j] == 'L') {
				bbakjo.push_back({ i, j });	// ���� �ε��� ����.
			}
			// ������ �ִ� ��ġ�� ���̱⿡ ������ġ�� water_Q�� �־���ϰ���
			// else if�� ���� �ȵȴ�.
			if (grid[i][j] == '.' || grid[i][j] == 'L') {
				water_q.push({ i, j }); // ���� �� Ž���� ��ġ ����.
				visited_water[i][j] = 1;	// �ʱ� �湮ó��
			}
		}
	}
	bbakjo_q.push({ bbakjo[0].first, bbakjo[0].second});
	visited_bbakjo[bbakjo[0].first][bbakjo[0].second] = 1; // �ʱ� �湮ó��

	int result = 0;
	if (bbakjo.size() >= 2) {
		while (1) {
			bool stop_flag = bbakjo_meet(bbakjo[1].first, bbakjo[1].second);
			if (stop_flag == true) break;
			melting();
			result++;
		}
		cout << result << "\n";
	}
	else {
		cout << result << "\n";
	}
	return 0;
}