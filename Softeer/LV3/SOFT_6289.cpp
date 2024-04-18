// https://softeer.ai/practice/6289
// �ҿ�ð� : 55��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define max_n 100004
int n = 0, m = 0, p_cnt = 0, weight[max_n];
bool res[max_n];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// �ʱ�ȭ
	fill(&res[0], &res[0] + max_n, true);

	cin >> n >> m;
	// �߷� �Է�.
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	// ģ�а��� �Է�
	int n1 = 0, n2 = 0;
	for (int i = 1; i <= m; i++) {
		cin >> n1 >> n2;
		// res ��� ���Ϳ� �ѹ��̶� false �� �Ǹ� �̰��� false�̴�. 
		if (weight[n1] <= weight[n2]) res[n1] = false;
		if(weight[n1] >= weight[n2]) res[n2] = false;
	}

	// ��� �� ����
	for (int i = 1; i <= n; i++) {
		if (res[i] == true) p_cnt++;
	}

	cout << p_cnt << "\n";
	return 0;
}