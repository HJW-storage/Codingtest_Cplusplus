#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& v, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//for (int i = 0; i < n-1; i++) {
	//	for (int j = 0; j < n -1 - i; j++) {
	//		int tmp;
	//		if (v[j] > v[j + 1]) {
	//			tmp = v[j];
	//			v[j] = v[j + 1];
	//			v[j + 1] = tmp;
	//		}
	//	}
	//}

	bubbleSort(v, n);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}