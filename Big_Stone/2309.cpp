#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SET_Height 100

int n = 9;
int r = 7;
vector<int> height(n);
bool flag = false;

void combi(int start, vector<int>& hv) {
	if (hv.size() == r) {
		int sum = 0;
		for (int it : hv) {
			// hv는 인덱스 정보가 저장되어 있는 벡터이다.
			sum += height[it];
		}
		if (sum == SET_Height) {
			vector<int> seven_height;
			for (int it : hv) {
				seven_height.push_back(height[it]);
			}
			sort(seven_height.begin(), seven_height.end());
			for (int it : seven_height) {
				cout << it << " ";
			}
			flag = true;
			return;
		}
		return;
	}


	for (int i = start + 1; i < n; i++) {
		hv.push_back(i);
		combi(i, hv);
		if (flag == true) {
			return;
		}
		hv.pop_back();
	}
	return;
}


int main() {
	// 난쟁이 키 입력 받아서 height 벡터에 저장. 
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	vector<int> idx;
	// combi 함수 호출
	combi(-1, idx);

	return 0;
}