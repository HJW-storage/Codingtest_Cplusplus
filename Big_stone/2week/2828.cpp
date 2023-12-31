// https://www.acmicpc.net/problem/2828

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0, j = 0, result = 0;
	cin >> n >> m;
	cin >> j;	// 사과의 개수

	// 1, m으로 인덱스 설정한 것은 이후 입력받는 position을 처리하기 더 용이하기 때문
	// 문제에서 거리의 최솟값을 구하라고 하였기에 처음과 끝 인덱스를 사용하여 로직을 구성하는게 쉽다.
	// 처음 또는 끝 인덱스 하나만 가지고 구성하기에는 어렵다. 구현의 되기는 할텐데 복잡해진다. 
	int box_firstidx = 1;
	int box_endidx = m;

	for (int i = 0; i < j; i++) {
		int position = 0;
		cin >> position;

		// 로직 구현
		if (box_firstidx <= position && box_endidx >= position) {
			continue;	// 상자 움직이지 않는다.
		}
		else {
			if (position > box_endidx) {
				while (position != box_endidx) {
					// box 인덱스는 처음과 끝이 같이 이동하게 되므로 반영해준다.
					box_endidx++;
					box_firstidx++;
					result++;
				}
			}
			else if (position < box_firstidx) {
				while (position != box_firstidx) {
					// box 인덱스는 처음과 끝이 같이 이동하게 되므로 반영해준다.
					box_firstidx--;
					box_endidx--;
					result++;
				}
			}
			else { ; }
		}
	}

	cout << result << "\n";
	return 0;
}