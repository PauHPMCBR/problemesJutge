#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
vector<vector<pair<ll,ll>>>v;

ll shortestPair = 1e17;
void bfs(ll x) {
	priority_queue<vector<ll>>pq;
	pq.push({0,0,x});
	vector<bool>visited(n,0);
	while (!pq.empty()) {
		ll d = -pq.top()[0];
		ll it = pq.top()[1];
		ll node = pq.top()[2];
		pq.pop();
		if (d >= shortestPair) continue;
		if (it == 0) for (auto [i,d2] : v[node]) {
			pq.push({-d2, 1, i});
		}
		else if (it == 1) {
			for (auto [i,d2] : v[node]) {
				if (i == x) continue;
				if (d2+d < shortestPair) shortestPair = d2+d;
			}
		}
	}
}

vector<ll>colour;
vector<ll>dist;
ll shortestPair2 = 1e17;
void bfs2(ll x) {
	dist = vector<ll>(n, 0);
	colour = vector<ll>(n, -1);
	priority_queue<vector<ll>>pq;
	pq.push({0,x});
	vector<bool>visited(n,0);
	colour[x] = 0;
	while (!pq.empty()) {
		ll d = -pq.top()[0];
		ll node = pq.top()[1];
		pq.pop();
		if (d >= shortestPair) continue;

		for (auto [i, d2] : v[node]) {
			if (colour[node] == colour[i]) {
				//cout << x << "  " << node << ' ' << dist[node] << "  " << i << dist[i] << endl;
				shortestPair2 = min(shortestPair2, max(dist[i], dist[node]));
			}
			else {
				if (colour[i] == -1) {
					pq.push({-(d+d2), i});
					dist[i] = d+d2;

				}
				colour[i] = !colour[node];
			}
		}
	}
}


int main(){
	cin >> t;
	while (t--) {
		cin >> n >> m;
		v = vector<vector<pair<ll,ll>>>(n);
		for (ll i = 0; i < m; ++i) {
			ll a,b,c;
			cin >> a >> b >> c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		for (ll i = 0; i < n; ++i) {
			bfs(i);
		}
		if (shortestPair != 1e17) {
			for (ll i = 0; i < n; ++i) {
				bfs2(i);
			}
			cout << min(shortestPair, shortestPair2) << endl;
		}
		else cout << "INF" << endl;
		shortestPair = 1e17;
	}
}