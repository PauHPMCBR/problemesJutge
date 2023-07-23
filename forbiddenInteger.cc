#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;

		vector<int>v(n+1, -1);
		v[0] = 0;
		for (int i = 1; i <= k; ++i) {
			if (i == x) continue;
			for (int j = 0; j <= n; ++j) {
				if (v[j] != -1 and j+i <= n) v[j+i] = j;
			}
		}
		if (v[n] != -1) {
			cout << "YES" << endl;
			vector<int>ans;
			int x = n;
			while (x != 0) {
				ans.push_back(x - v[x]);
				x = v[x];
			}
			cout << ans.size() << endl;
			for (auto i : ans) cout << i << ' ';
			cout << endl;
		}
		else cout << "NO" << endl;
	}
}