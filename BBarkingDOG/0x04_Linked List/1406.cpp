// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

list<char> editor; // linked-list Ȱ��
string init_str = "";
int n = 0;

void solve_editor(list<char>::iterator &cursor, string &tmp_command) {
	if (tmp_command.size() == 1) {
		if (tmp_command == "L") {
			if (cursor != editor.begin()) cursor--;
		}
		else if (tmp_command == "D") {
			if (cursor != editor.end()) cursor++;
		}
		else if (tmp_command == "B") {
			if (cursor != editor.begin()) {
				// ���簡��Ű�� Ŀ���� ��忡�� ���� �����Ͱ� ���⿡, �����ϸ� ����.
				// erase�� ���� ���� �̵���Ű�� �����־�� �Ѵ�.
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
	}
	else {
		// P $ �� ���.
		// insert�ϸ� iter���� ����(�տ�) ���ڰ� �߰��ȴ�.
		cursor = editor.insert(cursor, tmp_command[2]);
		cursor++; // ���ڸ� �߰��߱⿡ cursor�� �ϳ� ������Ų��.
	}

	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// �ʱ�ȭ
	editor.clear();
	auto cursor = editor.begin();

	cin >> init_str;
	// �ʱ� �Էµ� ���ڿ��� Linke-list�� �������ֱ�.
	for (int i = 0; i < init_str.length(); i++) {
		// push_back�ϸ� iterator cursor�� �ڵ����� ���Ḯ��Ʈ editor.end()�� ����Ų��.
		editor.push_back(init_str[i]);
	}


	cin >> n;
	string tmp_command = "";

	cin.ignore(); // ���๮�� ���ֱ�

	for (int i = 0; i < n; i++) {
		getline(cin, tmp_command); // ���پ� �Է� �ޱ�.
		solve_editor(cursor, tmp_command);
	}

	for (auto iter = editor.begin(); iter != editor.end(); iter++) {
		cout << *iter << "";
	}

	return 0;
}