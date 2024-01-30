// https://www.acmicpc.net/problem/11328

// 맨 처음 순열로 모든 경우의수를 생각. but, 최대길이 1000 -> 1000! 시간초과.
// 문자들을 카운팅하여 저장하자. 

#include <iostream>
#include <algorithm>

using namespace std;

int first_alpha[26];	// 소문자 알파벳 a~z : 26개
int second_alpha[26];	// 소문자 알파벳 a~z : 26개
int test_n = 0;
string first_str, second_str;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_n;	// 테스트 케이스 개수
	for (int i = 0; i < test_n; i++) {
		bool check_flag = true;
		// 테스트 케이스를 진행하는 것이므로 초기화 과정이 필요하다.
		first_str = "";	// 초기화
		second_str = ""; // 초기화
		fill(&first_alpha[0], &first_alpha[0] + 26, 0); // 초기화
		fill(&second_alpha[0], &second_alpha[0] + 26, 0); // 초기화

		cin >> first_str >> second_str;
		// 알파벳 개수 카운팅
		for (char it : first_str) { first_alpha[it - 'a']++; }
		for (char it : second_str) { second_alpha[it - 'a']++; }

		// 첫번쨰 str 섞어서 두번쨰 str이 되는지, 각 카운팅한 배열의 원소의 값을 비교한다. 
		// 원소의 카운팅 수가 같다면 성립한다.
		// 추가로, 
		for (int i = 0; i < 26; i++) {
			if (first_alpha[i] == second_alpha[i]) { continue; }
			else { check_flag = false; }
		}

		// 결과 출력
		if (check_flag == true) { cout << "Possible" << "\n"; }
		else { cout << "Impossible" << "\n"; }
	}
	return 0;
}