#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>v;

ll dfs(ll x) {
	if (v[x].size() == 0) return 1;
	if (v[x].size() == 1) return dfs(v[x][0])+1;
	return min(dfs(v[x][0]), dfs(v[x][1]))*2+1;
}

int main(){
	ll t,n;
	cin >> t;
	while (t--) {
		cin >> n;
		v = vector<vector<ll>>(n);
		for (ll i = 0; i < n-1; ++i) {
			ll a,b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		cout << dfs(0) << endl;
	}
}