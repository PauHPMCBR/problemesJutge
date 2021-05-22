#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>v;
vector<vector<ll>>trans;
vector<ll>dag;
vector<ll>tout;
vector<bool>visited;
void dfs(ll x) {
	for (auto i : v[x]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
	tout.push_back(x);
}

ll counter = 0;
void dfs2(ll x) {
	dag[x] = counter;
	for (auto i : trans[x]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs2(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	v = vector<vector<ll>>(n);
	trans = vector<vector<ll>>(n);
	visited = vector<bool>(n, false);
	dag = vector<ll>(n, -1);
	while (m--) {
		ll a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		trans[b-1].push_back(a-1);
	}
	for (ll i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}

	visited = vector<bool>(n, false);
	reverse(tout.begin(), tout.end());
	vector<ll>v2;
	for(auto i : tout) {
		v2.push_back(i);
		if (visited[i]) continue;
		++counter;
		visited[i] = true;
		dfs2(i);
	}
	vector<int>edge(counter, false);
	int sol = counter;
	for (auto i : v2) {
		for (auto j : v[i]) {
			if (dag[i] != dag[j]) {
				if (edge[dag[i]] == 0) --sol;
				++edge[dag[i]];
			}
		}
	}
	cout << sol << endl;
}