#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>w;
vector<ll>r;
ll t, n, m;
ll backtrack(ll x){
	if (w[x] == x) return x;
	else return backtrack(w[x]);
}
void join(ll x, ll y) {
	ll n1 = backtrack(x);
	ll n2 = backtrack(x);
	if (r[n1] > r[n2]) w[y] = n1;
	else {
		w[n1] = n2;
		if (r[n1] == r[n2]) ++r[n2];
	}
}



bool isConnected() {
	for (ll i = 0; i < n; ++i) {
		if (backtrack(i) != backtrack(0)) return false;
	}
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;

		r = vector<ll>(n);
		w = vector<ll>(n);
		for (int i = 0; i < n; ++i) w[i] = i;
		vector<pair<ll,pair<ll,ll>>>v;
		for (ll i = 0; i < m; ++i) {
			ll a,b,c;
			cin >> a >> b >> c;
			v.push_back(make_pair(c, make_pair(a,b)));
		}
		sort(v.begin(), v.end());
		ll sol = 0;
		for (ll i = 0; i < m; ++i) {
			ll c = v[i].first;
			ll a = v[i].second.first;
			ll b = v[i].second.second;
			join(a,b);
			sol = max(sol, c);
			
			if (isConnected()) break;
		}
		cout << sol << endl;
	}
}