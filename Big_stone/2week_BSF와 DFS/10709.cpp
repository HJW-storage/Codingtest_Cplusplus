// https://www.acmicpc.net/problem/10709

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h = 0, w = 0, cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> h >> w;
	//처음에 구름 이동을 백터 2개를 통해 하나 순회동안 나머지 하나 채우고, 나머지 하나 순회동안 나머지 하나 채우고
	//로 구현했더니 메모리 초과..... 
	//vector<pair<int, int>> pos_vec;
	//vector<pair<int, int>> next_pos_vec;
	
	//그래서, 큐로 대체해서 구현하였다. -> 제한된 메모리 안에 해결가능!!
	queue<pair<int, int>> q;

	vector<vector<int>> res_vec(h, vector<int>(w, -1));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char temp = ' ';
			cin >> temp;
			if (temp == 'c') {
				q.push({ i, j });
				//pos_vec.push_back({ i, j });
				res_vec[i][j] = 0;	// 비가 온 곳은 0으로 초기화.
			}
			else { ; }
		}
	}

	for (int i = 0; i < w - 1; i++) {
		cnt++;
		int q_size = q.size();
		for(int j = 0; j < q_size; j++) {
			int next_row = q.front().first;
			int next_col = q.front().second;
			next_col++;

			if (next_col <= w - 1) {
				q.push({ next_row, next_col });
				// 이미 구름이 지나갔던 곳은 또 변경되면 안된다.
				if (res_vec[next_row][next_col] == -1) {
					res_vec[next_row][next_col] = cnt;
				}
				else { ; }
			}
			q.pop();
		}
	}

	// 정답 출력
	for (int i = 0; i < res_vec.size(); i++) {
		for (int j = 0; j < res_vec[0].size(); j++) {
			cout << res_vec[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}