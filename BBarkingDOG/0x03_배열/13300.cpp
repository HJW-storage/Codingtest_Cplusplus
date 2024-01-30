// https://www.acmicpc.net/problem/13300

// 1. 초등학교는 1~6학년까지다.
// 2. 2차원 배열로 학년과 성별을 구분해서 학생수를 카운팅한다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int stu_arr[2][7] = { 0, };
	int n = 0, k = 0, gender = 0, grade = 0, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> gender >> grade;
		stu_arr[gender][grade]++;	// 학생수 카운팅
		}

	// 출력 찍어보기
	//for (int i = 0; i <= 1; i++) { // 성별
	//	for (int j = 1; j <= 6; j++) { // 학년
	//		cout << stu_arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// 남학생은 남학생끼리, 여학생은 여학생끼리 방을 배정해야 한다. 
	// 또한 한 방에는 같은 학년의 학생들을 배정해야 한다.
	// 풀이 로직 구현
	for (int i = 0; i <= 1; i++) { // 성별
		for (int j = 1; j <= 6; j++) { // 학년
			if (stu_arr[i][j] == 0) {
				continue;
			}
			else if (stu_arr[i][j] % k == 0) {
				res += stu_arr[i][j] / k;
			}
			else {
				res += stu_arr[i][j] / k;
				res += 1;  // 남은 학생들 배정하는 방 추가로 1개 더 존재.
			}
		}
	}
	cout << res << "\n";
	return 0;
}