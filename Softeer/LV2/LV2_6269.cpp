// https://softeer.ai/practice/6269

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M = 0, N = 0, K = 0;

bool check(int idx, vector<int>& ta, vector<int>& tb) {
	bool flag = true;
	for (int j = 0; j < ta.size(); j++) {
		if (tb[idx + j] == ta[j]) continue;
		flag = false;
		break;
	}
	return flag;
}
string solve(vector<int> &a, vector<int>& b) {
	string res = "";

	bool secret_success = false;

	int v_size = b.size();
	for (int i = 0; i <= v_size - M; i++) {
		if (b[i] == a[0]) {
			if(check(i, a, b)) secret_success = true;
		}
	}

	if (secret_success) res = "secret";
	else res = "normal";

	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// 입력
	cin >> M >> N >> K;

	vector<int> sceret_menu(M, 0);
	int tmp = 0;
	for (int i = 0; i < M; i++) {
		cin >> sceret_menu[i];
	}

	vector<int> push_order(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> push_order[i];
	}

	// 출력
	if (N < M) cout << "normal" << "\n";
	else {
		cout << solve(sceret_menu, push_order) << "\n";
	}

	return 0;
}