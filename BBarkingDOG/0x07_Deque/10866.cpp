// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	deque<int> dq;

	cin >> n;
	string _command = "";
	int _tmpX = 0;
	for (int i = 0; i < n; i++) {
		cin >> _command;

		if (_command == "push_front") {
			cin >> _tmpX;
			dq.push_front(_tmpX);
		}
		else if (_command == "push_back") {
			cin >> _tmpX;
			dq.push_back(_tmpX);
		}
		else if (_command == "pop_front") {
			if (dq.size()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if (_command == "pop_back") {
			if (dq.size()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if (_command == "size") {
			cout << dq.size() << "\n";
		}
		else if (_command == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (_command == "front") {
			if (dq.size()) cout << dq.front() << "\n";
			else cout << "-1\n";
		}
		else if (_command == "back") {
			if (dq.size()) cout << dq.back() << "\n";
			else cout << "-1\n";
		}
	}

	return 0;
}
