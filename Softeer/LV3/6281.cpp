// https://softeer.ai/practice/6281

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int n = 0, m = 0, grid[104][104] = { 0, }, visited[104][104] = { 0, };

void Qclear(queue<pair<int, int>> &tq) {
	queue<pair<int, int>> emptyq;
	swap(tq, emptyq);
}
int solve_bfs(int row, int col) {
	// bfs�� �����鼭 �������� �Ǿ� ���� ���ϴ� ���� 
	// ť�� �����ʰ� �ش� ���� ��ġ�� �湮 ǥ�ø� �صд�. �湮ǥ�ô� �����Ѵ�.
	// 2 �̻��� ������ ���� Ž�� ���� �����̹Ƿ� ť�� �־�ΰ� �������.
	
	visited[row][col] = 1; // �湮ó��
	queue<pair<int, int>> q;
	q.push({ row, col });

	queue<pair<int, int>> tmpq;
	int time_cnt = 0;
	while(1){
		while (q.size()) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			// �� ó�� �ʱ� bfs�� �־��� �迭 �����ڸ����� ���� ����� ���� �𼭸� �κб����� Ž��.
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + dr[i];
				int next_col = cur_col + dc[i];

				if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
				if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = 1; // �湮ó��
					q.push({ next_row, next_col }); // ���� ť�� �߰�
				}
			
				// �� ó�� bfs�� ������ 2���� bfs ���ʹ� ������ �湮 1�� ���� ���� 2�� �Ǹ鼭 �� ���� �ð���
				// ������ ������ ������Ʈ �ȴ�.
				if (grid[next_row][next_col] == 1) { // ���Ⱑ �ٽ� �κ��̴�.
					// ������ ��쿡�� ������ �������� ���� �湮�迭 �湮ǥ�ø� +1�� ���ش�.
					// �湮 ǥ�ð� 2�� �ȴٸ� �ش� ������ ���� �ɷ� �ٲ��ְ�, ���� bfs ������ ���� 
					// �ӽ� ť(tmpq) <����!! ���� q�� ������ �ȵȴ�. �ӽ�ť�� ����.>�� �־��ش�. 
					visited[next_row][next_col] = visited[next_row][next_col] + 1;
					if (visited[next_row][next_col] == 2) {
						tmpq.push({ next_row, next_col });
						grid[next_row][next_col] = 0; // ���� ��Ҵ�. 
					}
				}
			}
		}

		// ��������
		if (tmpq.size() == 0) break;

		time_cnt++;

		q = tmpq; // ť ����
		Qclear(tmpq); // ť ����
	}
	return time_cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	// �����ڸ����� ������ ������ �ʴ´ٰ� ��õ��ִ�. (0,0)���� ����.
	cout << solve_bfs(0, 0) << "\n";
	return 0;
}