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
		set<pair<int,int>>s;
		for (int i = 1; i < n; ++i) {
			s.insert({abs(v[i]-v[i-1]), i});
		}
		int ans = 0;
		for (int i = 0; i < n-k; ++i) {
			ans += (*s.begin()).first;
			s.erase(s.begin());
		}
		cout << ans << endl;
	}
}