//https://www.acmicpc.net/problem/2979

#include <iostream>
#include <algorithm>

using namespace std;

int A[101] = { 0, }, B[101] = { 0, }, C[101] = { 0, };
int truck_cnt[101] = { 0, };
int start = 0;
int last = 0;
int cost_a = 0, cost_b = 0, cost_c = 0;

int total_cost(int *t_cnt) {
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
		else {
			;
		}
	}

	return result;
}

void set_array(int start, int last, int set_arr[]) {
	for (int i = start + 1; i <= last; i++) {
		set_arr[i] = 1;
		truck_cnt[i]++;
	}
}

int main() {
	
	cin >> cost_a >> cost_b >> cost_c;

	for (int i = 1; i <= 3; i++) {
		cin >> start >> last;
		switch (i) {
			case 1:
				set_array(start, last, A);
				/*for (int i = start + 1; i <= last; i++) {
					A[i] = 1;
					truck_cnt[i]++;
				}*/
				break;
			case 2:
				set_array(start, last, B);
				/*for (int i = start + 1; i <= last; i++) {
					B[i] = 1;
					truck_cnt[i]++;
				}*/
				break;
			case 3:
				set_array(start, last, C);
				/*for (int i = start + 1; i <= last; i++) {
					C[i] = 1;
					truck_cnt[i]++;
				}*/
				break;
			default:
				;
		}
	}

	int result = total_cost(truck_cnt);
	cout << result << "\n";

	//for (auto it : truck_cnt) cout << it << " ";
	return 0;
}