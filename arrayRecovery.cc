#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		vector<int>ans(n);
		bool poassible = true;
		cin >> v[0];
		ans[0] = v[0];
		for (int i = 1; i < n; ++i) {
			cin >> v[i];
			if (ans[i-1] - v[i] >= 0 and v[i] != 0 and ans[i-1] != 0) poassible = false;
			else ans[i] = max(v[i] + ans[i-1], ans[i-1] - v[i]);
		}
		if (!poassible) cout << -1 << endl;
		else {
			for (auto i : ans) cout << i << ' ';
				cout << endl;
		}
	}
}