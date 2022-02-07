#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>v(n, 0);
	for (int i = 1; i < n; ++i) {
		int prov = v[i-1];
		while (prov > 0 && s[i] != s[prov]) {
			prov = v[prov-1];
		}
		if (s[i] == s[prov]) ++prov;
		v[i] = prov;
	}
	for (int i : v) cout << i << ' ';
	cout << endl;
}