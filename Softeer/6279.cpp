// https://softeer.ai/practice/6279

// 투포인터 활용. 
// 부품 idx, 로봇 idx 저장한 벡터의 각각 포인터를 하나 잡고 비교하면 O(n) 으로 풀자.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0, k = 0, res = 0;
char arr[20004];
vector<int> robot, component;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	char tmp = 'a';
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 'P') robot.push_back(i);
		else if (tmp == 'H') component.push_back(i);
	}

	int robot_idx = 0;
	int robot_end = robot.size();
	int comp_idx = 0;
	int comp_end = component.size();

	while ( (robot_idx < robot_end) && (comp_idx < comp_end) ) {
		int diff = robot[robot_idx] - component[comp_idx];
		if (diff >= -k && diff <= k) {
			res++;
			comp_idx++;
			robot_idx++;
		}
		else if (diff < -k) robot_idx++;
		else if (diff > k) comp_idx++;
	}

	cout << "res : " << res << "\n";
	return 0;
}