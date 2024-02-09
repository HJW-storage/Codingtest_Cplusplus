// https://www.acmicpc.net/problem/4949
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string str = "";
		getline(cin, str);

		if (str == ".") break;

		vector<char> vec;
		for (char it : str) {
			if (it == '(' || it == '[') {
				vec.push_back(it);
			}
			else if (it == ')') {
				if (vec.size() && *(vec.end() - 1) == '(') {
					vec.pop_back();
				}
				else {
					vec.push_back(it);
				}
			}
			else if (it == ']') {
				if (vec.size() && *(vec.end() - 1) == '[') {
					vec.pop_back();
				}
				else {
					vec.push_back(it);
				}
			}
		}

		if (vec.size() == 0) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}