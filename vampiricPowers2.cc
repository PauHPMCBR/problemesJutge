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

		vector<int>v(n);
		cin >> v[0];
		int ans = v[0];
		vector<vector<bool>>b(n, vector<bool>(257, false));
		b[0][v[0]] = true;
		for (int i = 1; i < n; ++i) {
			cin >> v[i];
			b[i][v[i]] = true;
			ans = max(ans, v[i]);
			for (int j = 0; j <= 256; ++j) {
				if (b[i-1][j]) {
					b[i][v[i] ^ j] = true;
					ans = max(ans, v[i] ^ j);
				}
			}
		}

		cout << ans << endl;

	}
}