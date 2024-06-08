// https://www.acmicpc.net/problem/17478

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;

string prePlus = "____";
string str1 = "����Լ��� ������?";
string str2 = "�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
string str3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
string str4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.";

string str5 = "����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����";
string str6 = "��� �亯�Ͽ���.";

void printV_pre(int &cnt) {
	for (int i = 0; i < cnt; i++) {
		cout << prePlus;
	}
	return;
}
void go(int cnt) {
	// �������
	if (cnt > n) return;

	if(cnt < n){
		printV_pre(cnt);
		cout << "\"" << str1 << "\"" << "\n";
		printV_pre(cnt);
		cout << "\"" << str2 << "\n";
		printV_pre(cnt);
		cout << str3 << "\n";
		printV_pre(cnt);
		cout << str4 << "\"" << "\n";
	}
	else if (cnt == n) {
		printV_pre(cnt);
		cout << "\"" << str1 << "\"" << "\n";
		printV_pre(cnt);
		cout << "\"" << str5 << "\"" << "\n";
	}
	go(cnt + 1);

	printV_pre(cnt);
	cout << str6 << "\n";

	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	go(0);

	return 0;
}