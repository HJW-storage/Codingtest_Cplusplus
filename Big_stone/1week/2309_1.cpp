// https://www.acmicpc.net/problem/2309

// 그냥 깡 구현으로 풀었다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define person 9
#define set_height 100

int main() {
	vector<int> v_height;

	// 9 난쟁이의 키를 입력받는다.
	int sum_nine = 0;
	for (int i = 0; i < person; i++) {
		int in_height;
		cin >> in_height;
		sum_nine += in_height; // 9 난쟁이 키의 합을 구한다.
		v_height.push_back(in_height);
	}

	// 오름차순 정렬
	sort(v_height.begin(), v_height.end());

	bool stop_flag = false;
	// 2중 for문을 통해 2명의 키를 제외하며 7명의 키의 합이 100인 경우를 구한다.
	for (int i = 0; i < person; i++) {
		for (int j = i + 1; j < person; j++) {
			if (i == j) {
				continue; // 예방차원 예외처리
			}
			int temp_height = sum_nine;	// 임시 변수에 저장해서 비교한다. 
			temp_height = sum_nine - v_height[i] - v_height[j];
			if (temp_height == set_height) {
				stop_flag = true;
				for (int k = 0; k < person; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << v_height[k] << "\n";
				}
				break;
			}
		}
		if (stop_flag) {
			break;
		}
	}

	return 0;
}