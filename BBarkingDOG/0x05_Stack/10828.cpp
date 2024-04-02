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
	cin.ignore(); // �� �κ��� �߰��Ͽ� ���� ���ڸ� �����մϴ�.
	//getline(cin, command);

	/*
	cin >> n;�� ����ϸ� ����ڷκ��� ���� n�� �Է¹�����, ���Ŀ� ���� �ִ� ���� ����(\n)�� �������� �ʽ��ϴ�. 
	��, ����ڰ� n�� �Է��ϰ� ���͸� ġ��, �� ����(���� ����)�� �Է� ��Ʈ���� ���� �ְ� �˴ϴ�. 
	ù ��° getline ȣ���� �ٷ� �� ���� ���ڸ� �о� �鿩�� �� ���ڿ��� command�� �����ϰ�, 
	������ ����ڰ� �ǵ��� ù ��° ��ɾ� �Է��� �ޱ� ���� for ������ ù ��° �ݺ��� ����˴ϴ�. 
	���������, �ϳ��� �Է��� ��ǻ� ���õǾ� ���̴� ������ �߻��մϴ�.
	*/
	for (int i = 0; i < n; i++) {
		getline(cin, command);
		if (command.find(" ") != string::npos) {
			// ���Ⱑ ������ �ش� ����� push x �̴�. 
			stk.push(stoi(command.substr(command.find(" ") + 1, command.size() - 1))); // ���ÿ� X �ױ�.
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
