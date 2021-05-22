#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, w;
vector<vector<vector<char>>>prov;
vector<pair<ll,ll>> dist;


ll getDiff(ll x, ll y) {
	ll lel = 0;
	for (ll i = 0; i < n; ++i)
		for (ll j = 0; j < m; ++j)
			if (prov[x][i][j] != prov[y][i][j]) ++lel;
	return lel;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> w;
	dist = vector<pair<ll,ll>>(k, {1e6,-1});
	prov = vector<vector<vector<char>>>(k, vector<vector<char>>(n, vector<char>(m)));
	for (ll i = 0; i < k; ++i) {
		for (ll j = 0; j < n; ++j) {
			for (ll l = 0; l < m; ++l) {
				cin >> prov[i][j][l];
			}
		}
	}
	vector<bool>visited(k, false);
	vector<pair<ll, ll>> ans;
	ll sol = 0;
	for (ll i = 0; i < k; ++i) {
		ll a = -1;
		ll b = -1;
		for (ll j = 0; j < k; ++j) {
			if (visited[j]) continue;
			if (a == -1 || dist[j].first < dist[a].first) {
				a = j;
				b = dist[j].second;
			}
		}
		visited[a] = true;
		if (dist[a].first*w > n*m) {
			ans.push_back({a+1, 0});
			sol += n*m;
		}
		else {
			ans.push_back({a+1, b+1});
			sol += dist[a].first * w;
		}
		for (ll j = 0; j < k; ++j) {
			if (visited[j]) continue;
			ll cur = getDiff(a, j);
			if (cur < dist[j].first) {
				dist[j].first = cur;
				dist[j].second = a;
			}
		}
	}

	cout << sol << endl;
	for (auto lel : ans) cout << lel.first << ' ' << lel.second << endl;
}