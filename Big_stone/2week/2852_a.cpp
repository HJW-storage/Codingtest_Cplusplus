// https://www.acmicpc.net/problem/2852

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n = 0, team = 0, a = 0, b = 0, asum = 0, bsum = 0;
string cur_time;
string prev_time;

int change_sec(string &str) {
	string tsec1 = str.substr(0, 2);
	string tsec2 = str.substr(3, 2);
	int tsec = atoi(tsec1.c_str()) * 60 + atoi(tsec2.c_str());
	return tsec;
}
void go(int &res_sum, string cur_time) {
	res_sum += change_sec(cur_time) - change_sec(prev_time);
}

void printV(int &ssum) {
	string d = "00" + to_string(ssum / 60);
	string e = "00" + to_string(ssum % 60);
	string result = d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
	cout << result << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> team >> cur_time;
		if (a > b) {
			go(asum, cur_time);
		}
		else if (a < b) {
			go(bsum, cur_time);
		}
		team == 1 ? a++ : b++;
		prev_time = cur_time;
	}

	if (a > b) {
		go(asum, "48:00");
	}
	else if (a < b) {
		go(bsum, "48:00");
	}

	printV(asum);
	printV(bsum);

	return 0;
}