// https://www.acmicpc.net/problem/15686

// 해당 코드는 시간초과가 난다. 
// 신나게 코딩 다해보고 채점하니 시간초과로 인해 알고리즘을 다시 짯다. 
// 왜 시간 초과인지 직접 계산해보며 재고해보자.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, temp;
int chicken_street = 1000000;	// 최솟값을 구해야하므로 초기값을 큰값으로 정한다.
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

vector<vector<int>> grid(54, vector<int>(54, 0));
vector<vector<int>> visited(54, vector<int>(54, 0));
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int bfs(int row, int col) {
	// 테스트 케이스별로 검사해야하기에 방문처리 벡터 초기화 시켜주어야 한다.
	fill(visited.begin(), visited.end(), vector<int>(54, 0));
	visited[row][col] = 1;	// 방문처리
	queue<pair<int, int>> q;
	q.push({ row, col });
	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if (next_row >= 1 && next_row <= n && next_col >= 1 && next_col <= n) {
				// 치킨집 2가 보이면 거리 반환하고 종료
				if (grid[next_row][next_col] == 2) {
					return visited[cur_row][cur_col]; 
				}

				// 방문 검사만 해주면 된다.
				if (visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1;	// 최단거리
					q.push({ next_row, next_col });
				}
			}
		}
	}
}
// nCr 조합구하기 -> 인덱스를 기준으로 뽑은 것. 
// 인덱스로 뽑아야 중복되는 수가 주어졌을 경우 대응이 가능하다.
void combi(int start, int chicken_housecnt, vector<int>& b) {
	if (b.size() == m) {
		int dis = 0;
		// 초기화 중요하다. 변화시킨 것 마지막에 다시 변화시키고 나가기.
		for (int it : b) {
			grid[chicken[it].first][chicken[it].second] = 2;	// 치킨집 표시
		}

		// bfs 로직 들어가야한다. 
		for (pair<int, int> it : house) {
			dis += bfs(it.first, it.second);
		}

		// 최소 치긴 거리를 구하는 것이므로 더 작은 것을 비교하여 저장.
		chicken_street = min(chicken_street, dis);

		for (int it : b) {
			grid[chicken[it].first][chicken[it].second] = 0;	// 원상 복구하고 나가기
		}
		return;
	}

	for (int i = start + 1; i < chicken_housecnt; i++) {
		b.push_back(i);
		combi(i, chicken_housecnt, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 마을 정보 입력 받기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			// 치킨집 인덱스 정보만 벡터에 담고 grid에는 표시하지 않는다. 
			// 이후 조합을 뽑고 나서 치킨집으로 바꾸는 방법이 더 편한것 같아서 이렇게 진행.
			if (temp == 2) {
				chicken.push_back({ i, j });	// 치킨집 {row, col} 추가
				continue;
			}

			if (temp == 1) house.push_back({ i, j });	// 가정집 {row, col} 추가
			grid[i][j] = temp;
		}
	}

	int chicken_housecnt = chicken.size();
	vector<int> b;
	combi(-1, chicken_housecnt, b);

	cout << chicken_street << "\n";
	return 0;
}