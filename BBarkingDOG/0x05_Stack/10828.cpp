// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int n = 0;
string command;
stack<int> stk;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cin.ignore(); // 이 부분을 추가하여 개행 문자를 무시합니다.
	//getline(cin, command);

	/*
	cin >> n;을 사용하면 사용자로부터 정수 n을 입력받지만, 이후에 남아 있는 개행 문자(\n)를 제거하지 않습니다. 
	즉, 사용자가 n을 입력하고 엔터를 치면, 그 엔터(개행 문자)가 입력 스트림에 남아 있게 됩니다. 
	첫 번째 getline 호출이 바로 이 개행 문자를 읽어 들여서 빈 문자열을 command로 설정하고, 
	실제로 사용자가 의도한 첫 번째 명령어 입력을 받기 전에 for 루프의 첫 번째 반복이 종료됩니다. 
	결과적으로, 하나의 입력이 사실상 무시되어 보이는 현상이 발생합니다.
	*/
	for (int i = 0; i < n; i++) {
		getline(cin, command);
		if (command.find(" ") != string::npos) {
			// 띄어쓰기가 있으면 해당 명령은 push x 이다. 
			stk.push(stoi(command.substr(command.find(" ") + 1, command.size() - 1))); // 스택에 X 쌓기.
		}
		else {
			if (command == "pop") {
				if (stk.size()) {
					cout << stk.top() << "\n";
					stk.pop();
				}
				else {
					cout << "-1" << "\n";
				}
			}
			else if (command == "size") {
				cout << stk.size() << "\n";
			}
			else if (command == "empty") {
				if (stk.empty()) cout << "1" << "\n";
				else cout << "0" << "\n";
			}
			else if (command == "top") {
				if (stk.size()) cout << stk.top() << "\n";
				else cout << "-1" << "\n";
			}
		}
	}
	return 0;
}
