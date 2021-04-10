#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<vector<ll>>v;
vector<bool>visited;
vector<ll>bipartie;
ll c1 = 0, c2 = 0;

bool dfs(ll x) {
	if (bipartie[x]) ++c1;
	else ++c2;
	visited[x] = true;
	for (auto i : v[x]) {
		if (bipartie[i] == bipartie[x]) return false;
		if (!visited[i]) {
			bipartie[i] = !bipartie[x];
			if (!dfs(i)) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = vector<vector<ll>>(n);
	visited = vector<bool>(n, false);
	bipartie = vector<ll>(n, -1);
	ll a,b;
	for (ll i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	bipartie[0] = 0;
	if (!dfs(0)) cout << -1 << endl;
	else cout << c1*c2 - m << endl;
}