#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n, m;
vector<ll>v;
vector<vector<ll>>dp;

ll b(ll pos) {
	//cout << "enters " << pos << " with value " << v[pos] << endl;
	if (v[pos] < 1 || v[pos] > m) return 0;
	if (pos == n-1) return 1;
	if (dp[pos][v[pos]] != -1) return dp[pos][v[pos]];
	if (v[pos+1]) {
		//cout << "end, values are " << v[pos] << ' ' << v[pos+1] << " and returns " << (abs(v[pos] - v[pos+1]) < 2) << endl;
		return (abs(v[pos] - v[pos+1]) < 2);
	}
	v[pos+1] = v[pos];
	ll res = b(pos+1);
	v[pos+1] = v[pos]-1;
	res += b(pos+1);
	res %= mod;
	v[pos+1] = v[pos]+1;
	res += b(pos+1);
	res %= mod;
	v[pos+1] = 0;
	//cout << "exits " << pos << ' ' << v[pos] << ' ' << res << endl;
	return dp[pos][v[pos]] = res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = vector<ll>(n);
	dp = vector<vector<ll>>(n, vector<ll>(m+1, -1));
	for (ll i = 0; i < n; ++i) cin >> v[i];
	ll res = 1;
	ll start = 1;
	if (!v[0]) {
		res = 0;
		for (ll i = 1; i <= m; ++i) {
			v[0] = i;
			res += b(0);
			res %= mod;
		}
		while (v[start] == 0 && start < n) ++start;
	}
	for (ll i = start; i < n; ++i) {
		if (!v[i]) {
			ll prov = 0;
			for (ll j = v[i-1]-1; j <= v[i-1]+1; ++j) {
				v[i] = j;
				prov += b(i);
				prov %= mod;
			}
			res *= prov;
			res %= mod;
			++i;
			while (i < n && v[i] == 0) ++i;
		}
		else if (abs(v[i] - v[i-1]) > 1 && v[i-1] != 0) {
			res = 0;
			break;
		}
	}
	cout << res << endl;
}