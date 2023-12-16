// https://www.acmicpc.net/problem/10808
// map을 사용하여 풀이하였다.

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<char, int> mp;

int main() {
	
	string alphbet_str;
	cin >> alphbet_str;

	// 아스키코드 a : 97 ~ z : 97+26 까지 모든 알파벳을 map의 키값으로 미리 넣어둔다.
	for (int i = 97; i < (97 + 26); i++) {
		mp[i] = 0;
	}

	for (int i = 0; i < alphbet_str.length(); i++) {
		mp[alphbet_str[i]] += 1;
	}

	// auto it -> pair<char, int>로 써도 된다. 
	for (auto it : mp) {
		cout << it.second << " ";
	}

	return 0;
}