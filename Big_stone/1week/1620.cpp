// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
int n, m;
map<string, int> poketmon;
map<int, string> poketmon_1;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	string poket_name;
	for (int i = 1; i <= n; i++) {
		cin >> poket_name;
		poketmon[poket_name] = i;
		poketmon_1[i] = poket_name;
	}

	//for (auto it : poketmon) cout << it.first << " " << it.second << "\n";

	for (int i = 1; i <= m; i++) {
		string in_name;
		cin >> in_name;
		if (poketmon[in_name]) {
			//cout << "answer : " << poketmon[in_name] << "\n";
			cout << poketmon[in_name] << "\n";
		}
		else {
			/*cout << "answer : " << poketmon_1[stoi(in_name)] << "\n";*/
			cout << poketmon_1[stoi(in_name)] << "\n";
		}
	}

	return 0;
}