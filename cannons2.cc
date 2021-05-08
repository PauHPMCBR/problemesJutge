#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int pos = 0;
	bool gotSol = false;
	while (v[pos] != -1) {
		int prov = pos;
		pos = v[pos];
		v[prov] = -1;
		if (pos == n-1) {
			gotSol = true;
			break;
		}
	}
	cout << (gotSol ? "0" : "1") << endl;
}