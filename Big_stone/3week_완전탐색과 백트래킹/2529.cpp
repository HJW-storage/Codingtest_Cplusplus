// https://www.acmicpc.net/problem/2529
// 풀이시간 1시간 10분. 
// 순열로 풀어야 하는데 처음에 조합으로 생각을하여 시간 소비하였다.
// make_permutation 구현하는데 버벅거렸다. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int n = 10; // 0 ~ 9 까지의 수 조합이기에 n = 10으로 설정한다. 
int k = 0;
char duengho[10];	// 부등호 저장 배열. 
string num_str;
vector<string> res; // string으로 저장해야한다. k = 9인 경우 90억 대의 숫자이므로 int형 초과이다.

// 순열 잘 구성했는지 출력하며 확인해보기.
void printV(int r, vector<int>& v) {
	for (int i = 0; i < r; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return;
}
// 만든 수 조합이 부등호에 만족해서 들어가는지 검사하기.
bool check(int r, vector<int> &v) {
	for (int i = 0; i < r - 1; i++) {
		if (duengho[i] == '<') {
			if (v[i] < v[i + 1]) { ; }
			else { return false; }
		}
		else if (duengho[i] == '>') {
			if (v[i] > v[i + 1]) { ; }
			else { return false; }
		}
		else { ; }
	}
	return true;
}
// 순열 구현하기.
void make_permutation(int depth, int r, vector<int> &v) {
	// 기저사례
	if (depth == r) {
		//printV(k+1, v);

		// 검사 로직 추가. 
		if (check(r, v)) {
			num_str = ""; // 빈 문자열로 초기화
			for (int i = 0; i < r;i++) {
				num_str += to_string(v[i]);	// string으로 형변환.
			}
			res.push_back(num_str);
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		make_permutation(depth+1, r, v);
		swap(v[i], v[depth]);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> duengho[i];
	}
	
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	make_permutation(0, k + 1, v);

	// 문자열 대소 비교는 왼쪽부터 아스키코드 기반으로 비교한다.
	// 따라서, cmp 사용자함수를 통해
	//							 1순위로 문자열 길이를 통해 비교하고
	//							 2순위로 왼쪽부터 아스키 코드 비교해야한다.
	
	// 그러나, 해당문제는 문자열의 길이가 일정하기에 그냥 sort 함수를 사용해도 된다.
	sort(res.begin(), res.end());
	
	// 최대값 출력, 최솟값 출력.
	cout << *(res.end() - 1) << "\n";
	cout << res[0] << "\n";

	return 0;
}