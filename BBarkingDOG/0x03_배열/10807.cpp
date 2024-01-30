// https://www.acmicpc.net/problem/10807
#include <iostream>
#include <algorithm>
using namespace std;

int num_cnt[205];

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n = 0, v = 0, tmp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (tmp >= -100 && tmp <= 100) {
			num_cnt[tmp+100]++; // v가 -100 ~ +100 이므로 배열은 0~200으로 저장한다.
		}
	}
	cin >> v;
	
	cout << num_cnt[v+100] << "\n";

	return 0;
}