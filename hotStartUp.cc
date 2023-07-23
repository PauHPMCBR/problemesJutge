#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		vector<int>c(k+1);
		vector<int>h(k+1);
		for (int i = 0; i < k; ++i) cin >> c[i+1];
		for (int i = 0; i < k; ++i) cin >> h[i+1];
		vector<vector<int>>g(n+1, vector<int>(k+1, 1e18));

		g[1][0] = c[v[0]];
		for (int i = 2; i <= n; ++i) {
			int val = v[i-1];
			for (int j = 0; j <= k; ++j) {
				int score = g[i-1][j];
				if (score != 1e18) {
					if (val == v[i-2]) score += h[val];
					else score += c[val];
					g[i][j] = min(g[i][j], score);
				}

				score = g[i-1][j];
				if (score != 1e18) {
					if (val == j) score += h[val];
					else score += c[val];
					g[i][v[i-2]] = min(g[i][v[i-2]], score);
				}
				//cout << g[i][j];
			}
			//cout << endl;
		}

		int ans = 1e18;
		for (int j = 0; j <= k; ++j) { 
			ans = min(ans, g[n][j]);
		}
		cout << ans << endl;
	}
}