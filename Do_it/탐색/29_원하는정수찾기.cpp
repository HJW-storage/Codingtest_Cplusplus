#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		int start = 0;
		int end = n - 1;
		int flag = 0;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (v[mid] > target) {
				end = mid - 1;
			}
			else if (v[mid] < target) {
				start = mid + 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}


}