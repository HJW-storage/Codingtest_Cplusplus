// https://www.acmicpc.net/problem/1436

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int i = 666;
	while (n) {
		string movie_num = to_string(i);
		if (movie_num.find("666") != string::npos) n--;
		if (n != 0) i++;
	}
	cout << i << "\n";
	return 0;
}