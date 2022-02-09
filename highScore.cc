#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll n, m;
vector<vector<pi>>g;
vector<vector<int>>rev;
vector<int>visited;
vector<ll>d;
bool possible = true;
set<ll>sus;

bool dfs(ll x) {
	if (visited[x]) return 0;
	visited[x] = 1;
	for (auto a : rev[x]) {
		if (sus.count(a)) return 1;
		if (dfs(a)) return 1;
	}
	return 0;
}

void bellmanford() {
	d[0] = 0;
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n; ++j) {
			for (auto a : g[j]) {
				ll e = a.first;
				ll p = a.second;
				if (d[j]+p < d[e] && d[j] != 2*1e10) { //!!!
					d[e] = d[j]+p;
				}
			}
		}
	}
	for (int j = 0; j < n; ++j) {
		for (auto a : g[j]) {
			ll e = a.first;
			ll p = a.second;
			if (d[j]+p < d[e] && d[j] != 2*1e10) {
				sus.insert(e);
				d[e] = d[j]+p;
			}
		}
	}
	if (!sus.empty() && dfs(n-1)) {
		possible = false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	g = vector<vector<pi>>(n);
	rev = vector<vector<int>>(n);
	visited = vector<int>(n, 0);
	d = vector<ll>(n, 2*1e10);
	ll a, b, c;
	for (ll i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		g[a-1].push_back({b-1, -c});
		rev[b-1].push_back(a-1);
	}

	bellmanford();
	if (possible) cout << -d[n-1] << endl;
	else cout << -1 << endl;
}