// https://www.acmicpc.net/problem/1919

// 1. 영어 알파벳을 숫자 배열에 대응시켜 카운팅
// 2. 배열은 총 2개. (1st 문자열, 2nd 문자열)
// 3. 배열 2개를 비교하여 각 원소의 개수가 같게, 원소의 값이 다른 경우는 제거해야하는 수 카운트 수 증가.

#include <iostream>
#include <algorithm>

using namespace std;
string first_str, second_str;
int first_alpha[26], second_alpha[26], res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> first_str;
	for (char it : first_str) {
		first_alpha[it - 'a']++;
	}
	cin >> second_str;
	for (char it : second_str) {
		second_alpha[it - 'a']++;
	}

	// 풀이 로직 구현
	for (int i = 0; i < 26; i++) {
		if (first_alpha[i] == second_alpha[i]) {
			continue;
		}
		else { // 알파벳 개수가 다른 경우, 알파벳 개수 차이만큼 결과값에 더한다.
			res += abs(first_alpha[i] - second_alpha[i]);
		}
	}
	cout << res << "\n";

	return 0;
}