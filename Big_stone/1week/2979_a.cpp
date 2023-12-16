//https://www.acmicpc.net/problem/2979

#include <iostream>
#include <algorithm>

using namespace std;

int truck_cnt[101] = { 0, };
int start = 0;
int last = 0;
int cost_a = 0, cost_b = 0, cost_c = 0;

void total_cost(int* t_cnt) {
	int result = 0;
	for (int i = 1; i <= 100; i++) {
		if (t_cnt[i] == 1) {
			result += (t_cnt[i] * cost_a);
		}
		else if (t_cnt[i] == 2) {
			result += (t_cnt[i] * cost_b);
		}
		else if (t_cnt[i] == 3) {
			result += (t_cnt[i] * cost_c);
		}
		else {;}
	}

	cout << result << "\n";
}

int main() {
	cin >> cost_a >> cost_b >> cost_c;

	for (int i = 1; i <= 3; i++) {
		cin >> start >> last;

		// 시각은 이상 ~ 미만으로 구한다. 
		for (int j = start; j < last; j++) {
			truck_cnt[j]++;
		}
	}

	total_cost(truck_cnt);

	return 0;
}