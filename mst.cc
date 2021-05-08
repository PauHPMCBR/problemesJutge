#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	vector<vector<pair<ll,ll>>>v(n);
	while (m--) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1,c});
		v[b-1].push_back({a-1,c});
	}
	vector<ll>dist(n, 1e18);
	dist[0] = 0;
	vector<bool>visited(n, false);
	ll sol = 0;
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,0});
	while (!pq.empty()) {
		ll node = pq.top().second;
		ll d = -pq.top().first;
		pq.pop();
		if (d > dist[node]) continue;
		sol += dist[node];
		visited[node] = true;

		for (auto lel : v[node]) {
			if (!visited[lel.first] && dist[lel.first] > lel.second) {
				dist[lel.first] = lel.second;
				pq.push({-lel.second, lel.first});
			}
		}
	}
	cout << sol << endl;
}