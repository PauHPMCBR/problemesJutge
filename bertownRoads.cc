#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>v;
vector<ll>tin;
vector<ll>fup;
vector<ll>sol;

struct pair_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & s1) const {
        return s1.first*31+s1.second;
    }
};

ll timer = 1;
bool hasBridges(ll x, ll par) {
	tin[x] = timer;
	++timer;
	fup[x] = tin[x];
	for (auto i : v[x]) {
		if (tin[i] == 0) {
			if (hasBridges(i, x)) return true;
			fup[x] = min(fup[x], fup[i]);
			if (fup[i] > tin[x]) return true;
		}
		else if (i != par) {
			fup[x] = min(fup[x], tin[i]);
		}
	}
	return false;
}

vector<bool>visited;
unordered_set<pair<ll,ll>, pair_hash>s;
void dfs(ll x) {
	visited[x] = true;
	for (auto i : v[x]) {
		if (!s.count({x,i}) && !s.count({i,x})) {
			s.insert({x,i});
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	v = vector<vector<ll>>(n);
	tin = vector<ll>(n, 0);
	fup = vector<ll>(n, 0);
	for (ll i = 1; i <= m; ++i) {
		ll a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	if (hasBridges(0, -1)) cout << 0 << endl;
	else {
		visited = vector<bool>(n, false);
		dfs(0);
		for (auto [a,b] : s) cout << a+1 << ' ' << b+1 << endl;
	}
}