#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<ll>>v;
vector<bool>visited;

ll shortestCycle;
void bfs(ll x) {
	vector<ll>dist(n, 0);
	visited[x] = true;
	queue<pair<ll,ll>>q;
	q.push({x,-1});
	while (!q.empty()) {
		ll node = q.front().first;
		ll parent = q.front().second;
		q.pop();
		for (auto i : v[node]) {
			if (!visited[i]) {
				q.push({i,node});
				visited[i] = true;
				dist[i] = dist[node]+1;
			}
			else if (i != parent) {
				shortestCycle = min(shortestCycle, dist[node]+dist[i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = vector<vector<ll>>(n);
	while (m--) {
		ll a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	ll cycle = 1e5+5;
	for (ll i = 0; i < n; ++i) {
		visited = vector<bool>(n, false);
		shortestCycle = 1e5+5;
		bfs(i);
		++shortestCycle;
		if (shortestCycle < 1e5+5) if (shortestCycle < cycle) cycle = shortestCycle;
	}
	if (cycle == 1e5+5) cycle = -1;
	cout << cycle << endl;
}