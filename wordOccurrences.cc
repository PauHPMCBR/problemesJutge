#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	string s, t, s2;
	cin >> s2 >> t;
	s = t + '#' + s2;
	n = s.size();
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
	vector<int>ans;
	n = s2.size();
	for (int i = 0; i < n; ++i) {
		int pos = i + t.size() + 1;
		if (v[pos] >= t.size()) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i+1 << ' ';
	cout << endl;
}