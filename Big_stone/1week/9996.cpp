#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string pattern;
int n;

int main() {
	cin >> n;
	cin >> pattern;
	
	int pattern_idx = pattern.find('*');
	string pre = pattern.substr(0, pattern_idx);
	string suf = pattern.substr(pattern_idx + 1);


	for (int i = 0; i < n; i++) {
		bool pattern_match = true;
		string name_str;
		cin >> name_str;

		if ( pre.length() + suf.length() > name_str.length() ) {
			pattern_match = false;
		}
		else {
			if (pre == name_str.substr(0, pre.length()) && suf == name_str.substr(name_str.length() - suf.length())) {
				;
			}
			else {
				pattern_match = false;
			}
		}

		if (pattern_match) {
			cout << "DA" << "\n";
		}
		else {
			cout << "NE" << "\n";
		}
	}

	return 0;
}