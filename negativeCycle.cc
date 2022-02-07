#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<vector<pair<ll,ll>>>v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<pair<ll,ll>>>(n);
	for (ll i = 0; i < m; ++i) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1, c});
	}

	vector<ll>dist(n, 0);
	vector<ll>parent(n, -1);
	ll pos = -1;

	for (ll k = 0; k < n; ++k) {
		pos = -1;
		for (ll i = 0; i < n; ++i) {
			for (auto x : v[i]) {
				if (dist[i] + x.second < dist[x.first]) {
					dist[x.first] = dist[i] + x.second;
					parent[x.first] = i;
					pos = x.first;
				}
			}
		}
	}

	if (pos == -1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (ll i = 0; i < n; ++i) pos = parent[pos];
		vector<ll>cycle;
		for (ll i = pos; !(i == pos && cycle.size() > 1); i = parent[i]) {
			cycle.push_back(i);
		}
		cout << cycle.size() << endl;
		for (ll i = cycle.size()-1; i >= 0; --i) cout << cycle[i]+1 << ' ';
		cout << endl;
	}
}