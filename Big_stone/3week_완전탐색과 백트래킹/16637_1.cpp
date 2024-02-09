// https://www.acmicpc.net/problem/16637

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int idx[10] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
int n = 0;
string susik;
vector<int> result;
// 조합 구현
// 조합으로 괄호가 들어갈 경우의 수를 뽑아서 괄호를 추가한 수식 만들기
// 괄호로 되어 있는 수식을 괄호 먼저 계산해서 새로운 string 벡터에 저장하기.
// 이후, 순서대로 계산하기.

// (1) 조합 구현하기
void printV(vector<int>& b) {
	for (auto it : b) {
		cout << it << " ";
	}
	cout << "\n";
	return;
}
int oper(int a, char op, int b) {
	if (op == '+') { return a + b; }
	else if (op == '-') { return a - b; }
	else if (op == '*') { return a * b; }
	else { ; }
}
void cal(string& addgaulho) {
	vector<string> final_cal;
	for (int i = 0; i < addgaulho.length(); i++) {
		if (addgaulho[i] == '(') {
			// char -> int 로 바꾸기
			int gaulho_cal = oper(addgaulho[i + 1] - '0', addgaulho[i + 2], addgaulho[i + 3] - '0');
			// int -> string로 바꾸기
			final_cal.push_back(to_string(gaulho_cal));
			i += 4;
		}
		else {
			// char -> string 으로
			final_cal.push_back(string(1, addgaulho[i]));
		}
	}

	// string 벡터에는 이제 괄호는 계산되어 진 것이 들어가 있다.
	int res_tmp = stoi(final_cal[0]);	// string -> int로 
	for (int i = 0; i < final_cal.size(); i++) {
		if (final_cal[i] == "+") {
			res_tmp = res_tmp + stoi(final_cal[i + 1]);
			i++;
			continue;
		}
		else if (final_cal[i] == "-") {
			res_tmp = res_tmp - stoi(final_cal[i + 1]);
			i++;
			continue;
		}
		else if (final_cal[i] == "*") {
			res_tmp = res_tmp * stoi(final_cal[i + 1]);
			i++;
			continue;
		}
	}
	result.push_back(res_tmp);
	return;
}
void combi(int start, int n, int r, vector<int>& b) {
	// 기저 사례
	if (b.size() == r) {
		//printV(b);
		// 예외 처리
		int prev_it = 1000;
		bool except_flag = false;
		for (int it : b) {
			if (it - prev_it == 1) {
				except_flag = true; // 예외 상황에 걸림. 제외. 
			}
			prev_it = it;	// prev 값 대입. 
		}

		if (except_flag == false) {
			// 괄호 삽입하기.
			string tmp = susik;
			int cnt = 0;
			for (int it : b) {
				tmp.insert(idx[it] + cnt, "(");
				cnt++;
				tmp.insert(idx[it] + 3 + cnt, ")");
				cnt++;
			}
			//cout << "괄호 추가 : " << tmp << "\n";

			// 계산하기
			cal(tmp);
		}
		return;
	}

	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, n, r, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> susik;
	int n_len = n / 2;
	// n >= 5 이상일 때
	int res_o = susik[0] - '0';
	for (int i = 0; i < n; i++) {
		if (susik[i] == '+') {
			res_o = res_o + (susik[i + 1] - '0');
			i++;
			continue;
		}
		else if (susik[i] == '-') {
			res_o = res_o - (susik[i + 1] - '0');
			i++;
			continue;
		}
		else if (susik[i] == '*') {
			res_o = res_o * (susik[i + 1] - '0');
			i++;
			continue;
		}
	}
	result.push_back(res_o);	// 괄호 없는 일자로 쭉 계산한 경우. 해당 경우로, n=1일 때도 ok. 

	vector<int> b;
	for (int i = 1; i <= n_len; i++) {
		combi(-1, n_len, i, b);
	}

	// 최댓값 출력
	sort(result.begin(), result.end(), greater<int>());
	cout << result[0] << "\n";
	return 0;
}