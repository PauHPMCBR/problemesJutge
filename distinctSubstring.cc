#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, ans = 0;
	cin >> n;
	string p;
	cin >> p;
	for (ll k = n-1; k >= 0; --k) {
		string s = p.substr(k);
		vector<ll>v(s.size(), 0);
		ll l = 0, r = -1;
		for (ll i = 1; i < s.size(); ++i) {
			if (i <= r) v[i] = min(v[i-l], r-i+1);
			while (i+v[i] < s.size() && s[i+v[i]] == s[v[i]]) ++v[i];
			if (v[i] > 0 && i+v[i]-1 > r) {
				r = i+v[i]-1;
				l = i;
			}
		}
		ll prov = 0;
		for (ll i : v) prov = max(prov, i);
		ans += n-k-prov;
	}
	cout << ans << endl;
}