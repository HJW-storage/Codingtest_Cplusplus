// https://www.acmicpc.net/problem/16719
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int visited[104] = { 0, }, str_len = 0;;
vector<string> res_str;
vector<pair<int, string>> res;

bool check(int s_idx, int e_idx) {
	for (int i = s_idx; i < e_idx; i++) {
		if (visited[i] == 0) return false;
	}
	return true;
}

void go(int s_idx, int e_idx) {
	// test case 3번을 잘 보자.
	// 사전 순으로 빠른 알파벳을 찾고, 이후 재귀는 찾은 알파벳의 오른쪽에서 진행. 
	while (!check(s_idx, e_idx)) {
		int min_idx = 101;
		char min_ch = 'a'; // 97
		
		// 다음 사전 순으로 가장 빠른 알파벳 찾기. 
		for (int i = s_idx; i < e_idx; i++) {
			if (visited[i] == 1) continue; // 방문한 곳은 패스.
			if (min_ch > str[i]) {
				min_ch = str[i];
				min_idx = i;
			}
		}

		if (min_ch != 'a') {
			res.push_back({min_idx, string(1, min_ch)});
			sort(res.begin(), res.end()); // 정렬. (맨처음 입력받은 문자열의 idx를 같이 저장했기에 정렬해준다.)
			string tmp;
			for (pair<int,string> it : res) {
				tmp += it.second;
			}
			visited[min_idx] = 1;	// 방문처리.
			res_str.push_back(tmp); // res에 완성된 문자열 추가.
			go(min_idx, e_idx);	
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str;
	
	str_len = str.length();
	go(0, str_len); // ZOAC 출력 순서 문자열 구성하기. 
	for (string it : res_str) cout << it << "\n"; // 출력하기

	return 0;
}
