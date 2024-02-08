// https://www.acmicpc.net/problem/14729

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 입력 n <= 10,000,000     천만이어서 sort 도 시간초과다. nlogn도 시간초과.
// 입력 받는 학생의 점수를 우선순위 큐를 이용해서 입력 받는다.
int n = 0;
int main() {
	priority_queue<float, vector<float>, greater<float>> pq;
	float sco = 0.0f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sco;
		pq.push(sco);
	}

	for (int i = 0; i < 7; i++) {
		float tmp = 0.0f;
		tmp = pq.top();
		//cout 표현하려면 추가적으로 설정 및 작업이 필요.그냥 printf쓰자.
		printf("%.3f\n", tmp); // 실수는 printf 를 써서 출력하자. 
		pq.pop();
	}
	return 0;
}