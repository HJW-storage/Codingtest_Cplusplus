#include <iostream>
#include <algorithm>

using namespace std;
int FirstName_cnt[26] = { 0, }; // a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z


int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		FirstName_cnt[name[0] - 97]++;
	}

	//for (auto it : FirstName_cnt) cout << it << " ";
	bool PREDAJA = true;
	for (int i = 0; i < 26; i++) {
		if (FirstName_cnt[i] >= 5) {
			PREDAJA = false;
			cout << char(i + 97);
		}
	}

	if (PREDAJA) {
		cout << "PREDAJA" << "\n";
	}

	return 0;
}