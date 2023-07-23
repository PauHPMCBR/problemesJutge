#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string,int>m;
	vector<string>v(n);
	for (int i = 0; i < n; ++i) {
		string prov;
		cin >> prov;
		m[prov] = i;
		v[i] = prov;
	}
	cin >> n;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		int pos = m[s1];
		--m[s1];
		++m[s2];
		v[pos] = s2;
		v[pos-1] = s1;
	}
	for (string i : v) cout << i << endl;
}