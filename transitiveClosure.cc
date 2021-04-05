#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<ll>>v;
vector<ll>visited;
vector<ll>vertices;
ll it = -1;

void dfs(ll x) {
	for (auto i : v[x]) {
		if (visited[i] != -1) continue;
		visited[i] = it;
		dfs(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v = vector<vector<ll>>(n);
	visited = vector<ll>(n, -1);
	for (ll i = 0; i < m; ++i) {
		ll x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for (ll i = 0; i < n; ++i) {
		if (visited[i] != -1) {
			++vertices[visited[i]];
			continue;
		}
		++it;
		vertices.push_back(1);
		visited[i] = it;
		dfs(i);
	}
	ll total = 0;
	for (ll i = 0; i <= it; ++i) {
		total += vertices[i]*(vertices[i]-1);
	}
	cout << total/2 - m << endl;
}