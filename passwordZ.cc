#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	int n = s.size();
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
	
	int maxVal = 0;
	string ans = "Just a legend";
	for (int i = 0; i < n; ++i) {
		if (v[i] == n-i) {
			if (maxVal >= v[i]) {
				ans = s.substr(0,v[i]);
				break;
			}
		}
		maxVal = max(maxVal, v[i]);
	}
	cout << ans << endl;
}