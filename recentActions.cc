#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		vector<int>ans(n, -1);
		int pos = n-1;
		vector<bool>changed(n+m+1);

		for (int i = 0; i < m; ++i) {
			int prov;
			cin >> prov;
			if (changed[prov]) continue;
			changed[prov] = true;
			if (pos < 0) continue;
			ans[pos] = i+1;
			--pos;
		}

		for (auto i : ans) cout << i << ' ';
		cout << endl;
	}
}