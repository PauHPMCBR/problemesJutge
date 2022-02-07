#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while (cin >> n) {
	ll pisoMax = 0;
	vector<pair<pair<ll,ll>,ll>>v(n);
	for (ll i = 0; i < n; ++i) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[i] = {{a,b},c};
		pisoMax = max(pisoMax, b);
	}
	sort(v.begin(), v.end());
	ll l = 0;
    ll r = 1e6;
    while (l <= r) {
        ll mid = (l+r)/2;

        ll maxLvl = 0;
        for (ll i = 0; i < n; ++i) {
        	if (v[i].second > mid) continue;
        	if (v[i].first.first <= maxLvl) maxLvl = max(maxLvl, v[i].first.second);
        }

        if (maxLvl == pisoMax) {
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << l << endl;
}
}