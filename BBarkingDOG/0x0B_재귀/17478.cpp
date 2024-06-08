// https://www.acmicpc.net/problem/17478

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;

string prePlus = "____";
string str1 = "재귀함수가 뭔가요?";
string str2 = "잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string str3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string str4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.";

string str5 = "재귀함수는 자기 자신을 호출하는 함수라네";
string str6 = "라고 답변하였지.";

void printV_pre(int &cnt) {
	for (int i = 0; i < cnt; i++) {
		cout << prePlus;
	}
	return;
}
void go(int cnt) {
	// 기저사례
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
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

	go(0);

	return 0;
}