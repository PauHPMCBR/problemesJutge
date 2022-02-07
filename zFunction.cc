#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>v(n, 0);
	int l = 0, r = -1;
	for (int i = 1; i < n; ++i) {
		if (i <= r) v[i] = min(v[i-l], r-i+1);
		while (i+v[i] < n && s[i+v[i]] == s[v[i]]) ++v[i];
		if (v[i] > 0 && i+v[i]-1 > r) {
			r = i+v[i]-1;
			l = i;
		}
	}
	for (int i : v) cout << i << ' ';
	cout << endl;
}