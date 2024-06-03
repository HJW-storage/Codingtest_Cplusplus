// https://www.acmicpc.net/problem/5397
// string�� �̿��ؼ�, erase, insert �ϴ� �ð��ʰ�.... 
// Linked-List Ȱ���ؾ��Ѵ�.

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

string keylogger = "";
int test_Case = 0;
list<char> li; // linked-list Ȱ��

void solve_passwd() {
	
	li.clear(); // �ʱ�ȭ
	list<char>::iterator cursor = li.begin();

	// iterator �������� erase�� iterator ���ʿ� �߰�
	// iterator �������� insert�� iterator ���ʿ� �߰�. insert�� �ϸ�, iterator�� �ڵ����� �ϳ� ä�����鼭 �ݿ��ȴ�.
	for (char& it : keylogger) {
		if (it == '<') {
			if (li.size() && cursor != li.begin()) cursor--;
		}
		else if (it == '>') {
			if (li.size() && cursor != li.end()) cursor++;
		}
		else if (it == '-') {
			if (cursor != li.begin()) {
				// ���� ���� iter�� �Ű��� ���� erase�� ��� ��������.
				// �׳� iter = a.erase(iter); �� ������� ���� ��忡�� �ƹ��� ���� �������� �����Ƿ� ������ ����.
				cursor--;

				// linked list�� �ּ�(���ͷ����ͷ� ����Ǵ� ��.)
				// ����, erase�� �����, �ش� ���ͷ����͸� cursor�� �ٽ� �־��־�� ��.
				cursor = li.erase(cursor); 
			}
		}
		else { // ���ڿ� �߰�
			cursor = li.insert(cursor, it);
			cursor++; // Ŀ�� �ϳ� ����
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
		keylogger = ""; // �ʱ�ȭ
		cin >> keylogger;

		solve_passwd();
	}
	return 0;
}