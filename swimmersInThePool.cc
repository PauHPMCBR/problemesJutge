#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll mod = (1e9)+7;
	ll n;
	double l, t;
	cin >> l >> t >> n;
	vector<double>v(n);
	for (ll i = 0; i < n; ++i) {
		double x;
		cin >> x;
		v[i] = double(x*t)/l/2;
	}
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << ' '; cout << endl;
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ans += 2*i*ll(v[i]);
		ans -= (n-i-1)*ll(v[i]);
		ans %= mod;
	}
	cout << ans << endl;
}