#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while (cin >> n) {
	ll pisoMax = 0;
	vector<pair<ll,pair<ll,ll>>>v(n);
	for (ll i = 0; i < n; ++i) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[i] = {c,{a,b}};
		pisoMax = max(pisoMax, b);
	}
	sort(v.rbegin(), v.rend());
	vector<ll>piso(pisoMax+1, 0);
	for (ll x = 0; x < n; ++x) {
		for (ll i = v[x].second.first; i <= v[x].second.second; ++i) {
			piso[i] = v[x].first;
		}
	}
	ll maxLvl = 0;
	for (ll i = 0; i <= pisoMax; ++i) {
		maxLvl = max(maxLvl, piso[i]);
	}
	cout << maxLvl << endl;
}
}