// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		string ps = "";
		cin >> ps;
		vector<char> vec_ps;
		for (char it : ps) {
			if (it == '(') {
				vec_ps.push_back(it);
			}
			else if (it == ')') {
				if (vec_ps.size() && *(vec_ps.end() - 1) == '(') {
					vec_ps.pop_back();
					// pop_back() 을 할때에는 벡터의 크기도 확인하자. 
				}
				else {
					vec_ps.push_back(it);
				}
			}
		}

		if (vec_ps.size() == 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}