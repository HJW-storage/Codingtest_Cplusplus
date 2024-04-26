// https://softeer.ai/practice/6283

#include <iostream>
#include <algorithm>

using namespace std;

int gear[8] = { 0, };
bool ascending_flag = true, descending_flag = true, mixed_flag = true;

void ascending_flag_judge() {
	int start_gear = gear[0];
	for (int i = 1; i < 8; i++) {
		if (++start_gear != gear[i]) {
			ascending_flag = false;
			break;
		}
	}
	return;
}
void descending_flag_judge() {
	int start_gear = gear[0];
	for (int i = 1; i < 8; i++) {
		if (--start_gear != gear[i]) {
			descending_flag = false;
			break;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 8; i++) {
		cin >> gear[i];
	}

	ascending_flag_judge();
	descending_flag_judge();
	// Ãâ·Â
	if (ascending_flag) cout << "ascending" << "\n";
	else if (descending_flag) cout << "descending" << "\n";
	else if (mixed_flag) cout << "mixed" << "\n";

	return 0;
}

// test1
// 8 7 6 5 4 3 2 1
// output : descending

// test2
// 1 2 3 4 6 7 8 5
// output : mixed