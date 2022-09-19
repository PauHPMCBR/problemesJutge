#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll n, m;
vector<vector<pi>>g;
vector<ll>d;
bool possible = true;
set <ll>s;

void dfs(ll x) {
	if (x == n-1) return;
	for (auto a : g[x]) {
		if (!s.count(a.first)) {
			s.insert(a.first);
			dfs(a.first);
			s.erase(a.first);
		}
	}
}

void bellmanford() {
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (auto a : g[j]) {
				ll e = a.first;
				ll p = a.second;
				if (d[j]+p < d[e]) {
					d[e] = d[j]+p;
				}
			}
		}
	}
	dfs(0);
	for (int i = 0; i < n-1; ++i) {
		for (auto a : g[i]) {
			ll e = a.first;
			ll p = a.second;
			if (e == n-1) continue;
			if (d[i]+p < d[e] && s.count(i)) {
				possible = false;
				return;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	g = vector<vector<pi>>(n);
	d = vector<ll>(n, 2*1e10);
	ll a, b, c;
	for (ll i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		g[a-1].push_back({b-1, -c});
	}

	bellmanford();
	if (possible) cout << -d[n-1] << endl;
	else cout << -1 << endl;
}