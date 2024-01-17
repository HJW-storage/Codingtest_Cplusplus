// https://www.acmicpc.net/problem/16637
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> res;
const int idx[10] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
int n = 0;
string susik;
void printV(vector<int>& v) {
	for (int it : v) {
		cout << it << " ";
	}
	cout << "\n";
	return;
}
int operator_part(int i, char op, string& check_str) {
	if (op == '+') {
		return (check_str[i + 1] - 48) + (check_str[i + 3] - 48);	// 덧셈처리
	}
	else if (op == '-') {
		return (check_str[i + 1] - 48) - (check_str[i + 3] - 48);
	}
	else if (op == '*') {
		return (check_str[i + 1] - 48) * (check_str[i + 3] - 48);
	}
}
void cal_str(string& check_str) {
	vector<string> vec_str;
	for (int i = 0; i < check_str.size(); i++) {
		if (check_str[i] == '(') {
			string ttmp = to_string((operator_part(i, check_str[i + 2], check_str)));
			vec_str.push_back(ttmp);
			i += 4;
		}
		else {
			vec_str.push_back(string(1, check_str[i]));	// char를 string으로 형변환.
		}
	}

	//for (string it : vec_str) cout << it << " ";
	//cout << "\n";
	int res_o = stoi(vec_str[0]);
	for (int i = 0; i < vec_str.size(); i++) {
		if (vec_str[i] == "+") {
			res_o = res_o + stoi(vec_str[i + 1]);	// 덧셈처리	string을 int로 형변환.
			//cout << "\n" << res_o;
			i++;
			continue;
		}
		else if (vec_str[i] == "-") {
			res_o = res_o - stoi(vec_str[i + 1]);
			i++;
			//cout << "\n" << res_o;
			continue;
		}
		else if (vec_str[i] == "*") {
			res_o = res_o * stoi(vec_str[i + 1]);
			i++;
			//cout << "\n" << res_o;
			continue;
		}
	}
	//cout << "\n" << "res_o : " << res_o << "\n";
	res.push_back(res_o);
	return;
}
void combi(int start, int n_len, int r, vector<int> &v) {
	if (v.size() == r) {
		// 로직 구현.
		bool check_flag = true;
		int prev_it = 1000;
		for (int i = 0; i < v.size(); i++) {
			// 괄호를 열고 닫는 것을 고려하면 겹치는 부분을 제외해야하기에 idx 2이상 차이가 나게 뽑아햐한다.
			if (v[i] - prev_it == 1) {
				check_flag = false;
				break;
			}
			prev_it = v[i];
		}
		
		if (check_flag == true) {
			// 괄호 삽입하기. 
			//printV(v);
			string check_str = susik;
			int cnt = 0;
			for (int it : v) {
				check_str.insert(check_str.begin() + idx[it] + cnt, '(');
				cnt++;
				check_str.insert(check_str.begin() + idx[it] + 3 + cnt, ')');
				cnt++;
			}
			/*printV(v);*/
			//cout << "괄호 추가한 string : " << check_str;
			//cout << "\n";
			cal_str(check_str);
		}
		else { ; }
		return;
	}

	for (int i = start + 1; i < n_len; i++) {
		v.push_back(i);
		combi(i, n_len, r, v);
		v.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;	// 입력되는 n은 홀수 이다. 
	cin >> susik;

	// 괄호 없이 주어진 수식 차례로 구하는 식.
	int temp = susik[0] - '0';
	int res_o = temp;
	//cout << "\n" << temp;
	for (int i = 0; i < n; i++) {
		if (susik[i] == '+') {
			res_o = res_o + (susik[i + 1] - 48);	// 덧셈처리
			//cout << "\n" << res_o;
			i++;
			continue;
		}
		else if (susik[i] == '-') {
			res_o = res_o - (susik[i + 1] - 48);
			i++;
			//cout << "\n" << res_o;
			continue;
		}
		else if (susik[i] == '*') {
			res_o = res_o * (susik[i + 1] - 48);
			i++;
			//cout << "\n" << res_o;
			continue;
		}
	}
	res.push_back(res_o);
	//cout << "\n" << "res_o : " << res_o << "\n";
	// 조합에서 뽑는 인덱스 갯수 n_len 구하기
	int n_len = (n / 2);
	// 최대 괄호 갯수 
	int gaulho_mx = (n / 2) + 1;
	if (gaulho_mx % 2 != 0) {
		gaulho_mx = gaulho_mx - 1;
	}
	else { ; }

	// 괄호는 () 쌍으로 되있기에 ( 에 해당하는 것만 뽑는걸로 계산하자. 
	gaulho_mx = gaulho_mx / 2;
	
	//cout << "\n\n";
	//cout << "n_len : " << n_len << " gaulho_mx : " << gaulho_mx << "\n";
	vector<int> b;
	for (int i = 1; i <= gaulho_mx; i++) {
		b.clear();
		combi(-1, n_len, i, b);

	}
	sort(res.begin(), res.end());
	//for (auto it : res) cout << it << " ";
	//cout << "\n";
	cout << * (res.end() - 1) << "\n";
	return 0;
}