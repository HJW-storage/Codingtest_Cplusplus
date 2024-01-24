// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
int n = 0, m = 0, result = 1;
char grid[24][24];
int visited[24][24];
map<char, int> mp;
//unordered_map<char, int> mp;

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
void go(int row, int col, int dis) {
	result = max(result, dis);
	if (result == n * m || result == 26) return;

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			// 처음 가본 곳. 

			// map은 참조만 하더라도 자동으로 0이 채워진다. 한번도 방문하지 알파벳의 경우.
			if (mp[grid[next_row][next_col]] == 0) {
				mp[grid[next_row][next_col]] = 1; // map 에 추가하기.
				go(next_row, next_col, dis + 1);

				// erase로 썼더니 시간초과가 났다.... why? : erase를 사용하면 함수기에 라이브러리가서 찾아와야한다.
				// 따라서 O(logN)이라도 함수로 갔따오니까 미묘하지만 더 오래걸린다.
				// mp.erase(grid[next_row][next_col]); // 지워주며 나온다.

				// map에서 key 값 : grid[next_row][next_col] 찾아야 하므로 시간 복잡도는 O(logN)이다.
				// 이것은 erase와 달리 라이브러리가서 함수를 찾아오는것이 아니므로 같은 시간 복잡도여도 미묘하게 빠르다.
				mp[grid[next_row][next_col]] = 0; // 지워주며 나온다.

				// 제일 좋은 것은 map대신 unordered_map을 사용하면 삽입, 탐색이 O(1)의 시간이다.
				// 그러나, 최악의 경우는 O(N)이 걸린다. 
				// 해당문제에서 unordered_map으로하니 시간초과가 나는데,,,, 최악의 경우에 들어갔나보다....
				// 그러나, unordered_map에서도 erase 함수를 쓰면 시간 복잡도는 O(logN)이다. 

				// -> 결론은, 결국 map이나 unordered_map 참조만하게 되도 자동으로 기본값 0(int), false(bool) 값이 추가되기에
				// erase로 지우는 것 보다는 mp[grid[next_row][next_col]] = 0; 으로 value 값을 변경해서 방문, 미방문 처리로 구현하자.
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	mp[grid[0][0]] = 1; // 초기 방문처리 
	go(0, 0, 1);
	cout << result << "\n";

	return 0;
}