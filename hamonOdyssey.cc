#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = -1;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (a == -1) a = v[i];
			else a = a & v[i];
		}
		if (a != 0) cout << 1 << endl;
		else {
			int sol = 0;
			a = -1;
			for (int i = 0; i < n; ++i) {
				if (a == -1) a = v[i];
				else a = a & v[i];

				if (a == 0) {
					++sol;
					a = -1;
				}
			}
			cout << sol << endl;
		}
	}
}