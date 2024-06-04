// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

list<char> editor; // linked-list 활용
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
				// 현재가리키는 커서의 노드에는 이후 데이터가 없기에, 참조하면 에러.
				// erase는 이전 노드로 이동시키고 지워주어야 한다.
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
	}
	else {
		// P $ 의 경우.
		// insert하면 iter이터 왼쪽(앞에) 문자가 추가된다.
		cursor = editor.insert(cursor, tmp_command[2]);
		cursor++; // 문자를 추가했기에 cursor는 하나 증가시킨다.
	}

	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// 초기화
	editor.clear();
	auto cursor = editor.begin();

	cin >> init_str;
	// 초기 입력된 문자열을 Linke-list에 삽입해주기.
	for (int i = 0; i < init_str.length(); i++) {
		// push_back하면 iterator cursor는 자동으로 연결리스트 editor.end()를 가리킨다.
		editor.push_back(init_str[i]);
	}


	cin >> n;
	string tmp_command = "";

	cin.ignore(); // 개행문자 없애기

	for (int i = 0; i < n; i++) {
		getline(cin, tmp_command); // 한줄씩 입력 받기.
		solve_editor(cursor, tmp_command);
	}

	for (auto iter = editor.begin(); iter != editor.end(); iter++) {
		cout << *iter << "";
	}

	return 0;
}