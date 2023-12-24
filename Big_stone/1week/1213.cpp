// https://www.acmicpc.net/problem/1213

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string eng_name, result, reverse_cpy;
int name_cnt[26] = { 0, };	// 알파벳은 26개. 
char ins_char;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> eng_name;
	for (char name : eng_name) {
		name_cnt[name - 65]++;	// A : 65
	}

	// name_cnt[] 개수가 홀수 인 것은 오직 1개만 존재해야한다.
	int haulsu_cnt = 0;	// 홀수 개수 파악해서 저장하는 변수.
	int haulsu_idx = 1004; // 초기 값은 임의의 큰값으로 설정.
	for (int i = 0; i < 26; i++) {
		if (name_cnt[i] % 2 != 0) {
			haulsu_cnt++;	// 홀수 증가.
			haulsu_idx = i;
			if (haulsu_cnt > 1) { break; }	// 홀수 개수가 2이상이면 즉시 종료.
			else { ; }
		}
	}
	
	// 정답 출력
	if (haulsu_cnt > 1) {
		cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}
	else {
		// 홀수 갯수가 하나 있는 경우 문자열 중간에 삽입해줘야한다. 
		if (haulsu_idx <= 25) {
			ins_char = char(haulsu_idx + 65);
			name_cnt[haulsu_idx]--;
		}
		
		// 모두 짝수 갯수인 경우 절반씩 string 구성. 
		for (int i = 0; i < 26; i++) {
			if((name_cnt[i] != 0) && (name_cnt[i] % 2 == 0)){
				int half = name_cnt[i] / 2;
				while (half) {
					result += char(i + 65);
					half--;
					name_cnt[i]--;
				}
			}
		}
	}
	
	// reverse_cpy 초기화
	
	reverse_cpy = result; // string 에서의 대입연산자('=')는 기본적으로 깊은복사로 적용된다. 

	//// copy() 함수 방법으로 깊은 복사를 수행할 수 있다.
	//for (size_t i = 0; i < result.size(); i++) {
	//	reverse_cpy += "a";
	//}
	//copy(result.begin(), result.end(), reverse_cpy.begin());
	
	reverse(reverse_cpy.begin(), reverse_cpy.end());

	if (haulsu_idx <= 25) {
		result += char(ins_char);
	}

	result += reverse_cpy;
	cout << result << "\n";

	return 0;
}