#include <bits/stdc++.h>
using namespace std;
#define int long long

map<vector<int>,string>m;

vector<int> simplify(vector<int>v) {
	vector<int>v2 = vector<int>(v.begin(), v.end());
	sort(v2.begin(), v2.end(), greater<>());
	while (v2.size() > 1 and v2[v2.size()-1] == 0) v2.pop_back();
	return v2;
}

void f(vector<int>v) {
	// for (auto i : v) cout << i << ' ';
	//  	cout << "!" << endl;
	if (m.count(v)) return;
	string ans = "---";
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 1; j <= v[i]; ++j) {
			v[i] -= j;
			vector<int>prov = simplify(v);

			f(prov);

			string s = m[prov];
			//cout << s << "," << endl;
			if (ans == "---") ans = {s[2], s[0], s[1]};
			else {
				if (ans[0] != 'W' and s[2] == 'W' or ans[0] == 'L' and s[2] == 'D') ans = {s[2], s[0], s[1]};
				else if (ans[0] == s[2]) {
					if (ans[1] != s[0]) ans[1] = 'D';
					if (ans[2] != s[1]) ans[2] = 'D';
				}
			}
			//cout << ans << "." << endl;
			v[i] += j;
		}
	}
	//cout << v[0] << " _" << ans << "_" << endl;
	m[v] = ans;
}

signed main() {
	 ios_base::sync_with_stdio(0);
	 cin.tie(0);
	m[{0}] = "LWW";
	int n;
	while (cin >> n) {
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		v = simplify(v);
		f(v);
		cout << m[v] << endl;
	}
}