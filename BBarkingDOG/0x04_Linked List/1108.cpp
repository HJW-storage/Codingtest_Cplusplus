// https://www.acmicpc.net/group/workbook/view/19934/65912

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n = 0, k = 0;
vector<int> res;

void solve() {
	// 큐에 채워두기
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	// 요세푸스 순열 시작
	int cnt = 0;
	while (q.size()) {
		if (q.size() == 1) {
			res.push_back(q.front());
			q.pop();
		}
		else {
			int _tmp = q.front();
			cnt++;
			if (cnt == k) {
				res.push_back(q.front());
				q.pop();
				cnt = 0; // 초기화
			}
			else {
				q.push(_tmp);
				q.pop();
			}
		}
	}

	// 출력
	size_t vec_size = res.size();
	cout << "<";
	for (int i = 0; i < vec_size; i++) {
		if (i == vec_size - 1) cout << res[i];
		else cout << res[i] << ", ";
	}
	cout << ">";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	solve();

	return 0;
}