// https://www.acmicpc.net/problem/2309
// 순열을 이용한 풀이. 단, 해당 문제는 수가 적었기에 시간이 여유로워서 사용할 수 있었다. 
// algorithm 헤더파일에서 제공하는 next_permutation 함수를 사용하여 풀이. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v_height(9, 0); // 9명 키 저장 벡터 0으로 초기화

	for (int i = 0; i < 9; i++) {
		cin >> v_height[i];	// 키 입력
	}

	// next_permutation 순열을 사용하기 위해서는 반드시 오름차순 정렬이 선행되어야 한다!!!
	sort(v_height.begin(), v_height.end());

	do {
		int seven_heightSum = 0;
		for (int i = 0; i < 7; i++) {
			seven_heightSum += v_height[i];
		}
		if (seven_heightSum == 100) {
			for (int i = 0; i < 7; i++) {
				cout << v_height[i] << "\n";
			}
			break;
		}
	} while (next_permutation(v_height.begin(), v_height.end()));

	return 0;
}