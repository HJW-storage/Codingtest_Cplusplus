// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define PLUS 0
#define MINUS 1
#define MULTIPLE 2
#define DIVIDE 3

// �ִ� < 11! : ����Ž�� ����.
// �־��� ���� ������ �ٲٸ� �� �ȴ�.

// �������� ���� ���������� �� ���Ѵ�.
// ������ ����� ���� ���� C++14�� ������ ������. ��, ����� �ٲ� �� ���� ���ϰ�, �� ���� ������ �ٲ� �Ͱ� ����. 

// ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)�� ����

int num_arr[14] = { 0, }, plus_cnt = 0, minus_cnt = 0, multiple_cnt = 0, divied_cnt = 0;
int N = 0;
vector<int> result;

// types 0 : +, 1: -, 2: x, 3: / 
void go(int cnt, int prev_res, int plus, int minus, int multiple, int divide, int types) {
	// ���� ����
	if (plus < 0 || minus < 0 || multiple < 0 || divide < 0) return;
	if (cnt == N) {
		result.push_back(prev_res);
		return;
	}

	int tmp_plus = plus, tmp_minus = minus, tmp_multiple = multiple, tmp_divide = divide;

	int cur_res = 0;
	if (types == PLUS) {
		tmp_plus--;
		cur_res = prev_res + num_arr[cnt];
	}
	else if (types == MINUS) {
		tmp_minus--;
		cur_res = prev_res - num_arr[cnt];
	}
	else if (types == MULTIPLE) {
		tmp_multiple--;
		cur_res = prev_res * num_arr[cnt];
	}
	else if (types == DIVIDE) {	
		tmp_divide--;
		if ((prev_res < 0 && num_arr[cnt] < 0) || prev_res >= 0 && num_arr[cnt] > 0) {
			cur_res = int(abs(prev_res) / abs(num_arr[cnt]));
		}
		else {
			cur_res = int(abs(prev_res) / abs(num_arr[cnt]));
			cur_res = cur_res - 2 * cur_res;
		}
	}
	
	go(cnt + 1, cur_res, tmp_plus, tmp_minus, tmp_multiple, tmp_divide, PLUS);
	go(cnt + 1, cur_res, tmp_plus, tmp_minus, tmp_multiple, tmp_divide, MINUS);
	go(cnt + 1, cur_res, tmp_plus, tmp_minus, tmp_multiple, tmp_divide, MULTIPLE);
	go(cnt + 1, cur_res, tmp_plus, tmp_minus, tmp_multiple, tmp_divide, DIVIDE);

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// �Է�
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num_arr[i];
	}

	cin >> plus_cnt >> minus_cnt >> multiple_cnt >> divied_cnt;

	go(1, num_arr[0], plus_cnt, minus_cnt, multiple_cnt, divied_cnt, PLUS);
	go(1, num_arr[0], plus_cnt, minus_cnt, multiple_cnt, divied_cnt, MINUS);
	go(1, num_arr[0], plus_cnt, minus_cnt, multiple_cnt, divied_cnt, MULTIPLE);
	go(1, num_arr[0], plus_cnt, minus_cnt, multiple_cnt, divied_cnt, DIVIDE);

	sort(result.begin(), result.end());

	cout << *(result.end() - 1) << "\n";
	cout << *(result.begin()) << "\n";

	return 0;
}

