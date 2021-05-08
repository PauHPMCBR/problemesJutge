#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>>v;

ll getDist(ll i, ll j) {
	return (v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second);
}

int main(){
	ll n;
	cin >> n;
	v = vector<pair<ll,ll>>(n);
	vector<bool>visited(n, false);
	ll sol = 0;
	for (ll i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
	vector<ll>dist(n, 1e17);
	dist[0] = 0;

	for (ll i = 0; i < n; ++i) {
		ll node = -1;
		for (ll j = 0; j < n; ++j) {
			if (!visited[j] && (node == -1 || dist[node] > dist[j])) {
				node = j;
			}
		}
		sol += dist[node];
		visited[node] = true;

		for (ll j = 0; j < n; ++j) {
			if (!visited[j]) {
				dist[j] = min(dist[j], getDist(node,j));
			}
		}
	}
	cout << sol << endl;
}