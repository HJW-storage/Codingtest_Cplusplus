#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int name_cnt[200] = { 0, }; // 대문자 A : 65 ~ Z : 65 + 25
string eng_name, result;
char mid;
int flag = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> eng_name;
	for (char name : eng_name) {
		name_cnt[name]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if(name_cnt[i]){
			// 홀수이면 : 단 홀수는 2개 이상이면 오답. 
			if (name_cnt[i] & 1) {
				mid = char(i);
				flag++;
				name_cnt[i]--;
			}
			if (flag > 1) {
				break;	// 해당 break 는 if ~ else 조건문을 탈출하는 것이다. 
			}
			// 짝수일 때,
			for(int j = 0; j < name_cnt[i]; j += 2){
				// 앞뒤로 붙이기
				result = result + char(i);
				result = char(i) + result;
			}
		}
	}

	if (flag > 1) cout << "I'm Sorry Hansoo" << "\n";
	else if (flag == 1) {
		result.insert(result.begin() + result.size() / 2, mid);
		cout << result << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}