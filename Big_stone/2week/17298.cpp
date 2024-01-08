// https://www.acmicpc.net/problem/17298
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int num_arr[1000004];
stack<pair<int, int>> num_stk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill(num_arr, num_arr + 1000004, -1);	// -1로 초기화
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		if (i == 1) {
			num_stk.push({ i, temp });
		}
		else{
			while (num_stk.size() != 0 && num_stk.top().second < temp) {
				num_arr[num_stk.top().first] = temp;
				num_stk.pop();
			}
			num_stk.push({i, temp});	// {idx, value}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << num_arr[i] << " ";
	}
	cout << "\n";
	return 0;
}