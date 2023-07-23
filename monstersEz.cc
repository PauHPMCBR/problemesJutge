#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		int sol = v[0]-1;
		v[0] = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] == v[i-1]) continue;
			sol += v[i] - v [i-1] - 1;
			v[i] = v[i-1] + 1;
		}
		cout << sol << endl;
	}
}