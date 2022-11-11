#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll>v(n);
		for (ll i = 0; i < n; ++i) {
			cin >> v[i];
		}
		ll diff = 0;
		ll ans = 0;
		for (ll i = 0; i < n; ++i) {
			ll prov;
			cin >> prov;
			ans += v[i]-prov;
			if (v[i] != prov) ++diff;
		}
		ans = abs(ans);
		if (diff != ans) ++ans;
		cout << ans << endl;
	}
}