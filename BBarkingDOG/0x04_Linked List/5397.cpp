// https://www.acmicpc.net/problem/5397
// string을 이용해서, erase, insert 하니 시간초과.... 
// Linked-List 활용해야한다.

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

string keylogger = "";
int test_Case = 0;
list<char> li; // linked-list 활용

void solve_passwd() {
	
	li.clear(); // 초기화
	list<char>::iterator cursor = li.begin();

	// iterator 기준으로 erase는 iterator 앞쪽에 추가
	// iterator 기준으로 insert는 iterator 뒤쪽에 추가. insert를 하면, iterator는 자동으로 하나 채워지면서 반영된다.
	for (char& it : keylogger) {
		if (it == '<') {
			if (li.size() && cursor != li.begin()) cursor--;
		}
		else if (it == '>') {
			if (li.size() && cursor != li.end()) cursor++;
		}
		else if (it == '-') {
			if (cursor != li.begin()) {
				// 이전 노드로 iter를 옮겨준 다음 erase를 써야 지워진다.
				// 그냥 iter = a.erase(iter); 를 써버리면 현재 노드에는 아무런 값도 써져있지 않으므로 오류가 난다.
				cursor--;

				// linked list는 주소(이터레이터로 연결되는 것.)
				// 따라서, erase로 지우고, 해당 이터레이터를 cursor에 다시 넣어주어야 함.
				cursor = li.erase(cursor); 
			}
		}
		else { // 문자열 추가
			cursor = li.insert(cursor, it);
			cursor++; // 커서 하나 증가
		}
	}

	for (char &it : li) cout << it;
	cout << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> test_Case;
	while (test_Case--) {
		keylogger = ""; // 초기화
		cin >> keylogger;

		solve_passwd();
	}
	return 0;
}