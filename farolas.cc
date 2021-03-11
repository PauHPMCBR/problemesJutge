#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,m;
	cin >> t;
	while (t--) {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> n >> m;
		vector<pair<int,int>>f(m);
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int radi, pos;
		for (int i = 0; i < m; ++i) {
			cin >> pos >> radi;
			f[i].first = pos-radi;
			f[i].second = pos+radi;
		}
		sort(v.begin(), v.end());
		sort(f.begin(), f.end());
		int minim = 0;
		bool possible = true;
		if (n == 0) cout << 0 << endl;
		else {
			int pos=-1;
			for (int i = 0; i < n && possible; ++i) {
				if (v[i] <= pos) continue;

				int maxim = -1;
				for (int j = 0; j < m; ++j) {
					if (f[j].first <= v[i] && f[j].second >= v[i]) {
						maxim = max(maxim, f[j].second);
					}
				}
				if (maxim == -1) {
					possible = false;
					break;
				}
				pos = maxim;
				++minim;
			}
			if (!possible) cout << "imposible" << endl;
			else cout << minim << endl;
		}
	}
}