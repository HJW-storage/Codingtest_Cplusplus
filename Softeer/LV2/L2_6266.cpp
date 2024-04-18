// https://softeer.ai/practice/6266

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n = 0, m = 0;
int time_tb[54][20] = { 0, };
map<string, int> mp;
vector<string> str_vec;

void scheduling_tb(string &tp, int &s, int &e) {
	for (int i = s; i < e; i++) {
		time_tb[mp[tp]][i] = 1; // �̹� ������ ���ִٴ� ǥ��. 
	}
	return;
}

void cal_tb(int idx) {
	
	vector<pair<int, int>> vp;
	int fir = 0, ed = 0;
	for (int i = 9; i < 18; i++) {
		if (time_tb[idx][i] == 0) {
			int fir = i;
			while (time_tb[idx][++i] == 0) {
				if (i >= 18) break;
				;
			}
			int ed = i;
			vp.push_back({ fir, ed });
		}
	}

	if (vp.size() == 0) {
		cout << "Not available" << "\n";
	}
	else {
		cout << vp.size() << " available:" << "\n";
		for (int i = 0; i < vp.size(); i++) {
			if (vp[i].first < 10) {
				cout << "0";
			}
			cout << vp[i].first << "-" << vp[i].second << "\n";
		}
	}
	

	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// �Է�
	cin >> n >> m;
	string tmp;
	// �� �̸��� �ش��ϴ� �ε������� map���� ����.
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		str_vec.push_back(tmp);
		mp[tmp] = i;
	}
	// ���� ���̺� 
	int t_s = 0, t_e = 0;
	for (int i = 0; i < m; i++) {
		cin >> tmp >> t_s >> t_e;
		scheduling_tb(tmp, t_s, t_e);
	}


	// ���.
	sort(str_vec.begin(), str_vec.end()); // ȸ�ǽ� �̸� �������� ����.
	int key_idx = 0;
	for (int i = 0; i < n; i++) {
		key_idx = mp[str_vec[i]];
		cout << "Room " << str_vec[i] << ":" << "\n";
		cal_tb(key_idx);
		if (i == n - 1) continue;
		cout << "-----" << "\n";
	}

	return 0;
}