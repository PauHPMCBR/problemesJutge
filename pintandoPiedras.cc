#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, c;
vector<ll>v;
vector<vector<ll>>dp;
ll MOD = ll(1e9+7);

ll same(ll pos, )

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> c;
		v = vector<ll>(n+1);
		dp = vector<pair<ll,ll>>(n+1, {-1,-1}); //canviar prevColor to isS
		bool possible = true;
		cin >> v[0];
		for (ll i = 1; i < n; ++i) {
			cin >> v[i];
			if (v[i] == v[i-1] && v[i] != 0) possible = false;
		}
		if (!possible) cout << 0 << endl;
		else {
			ll total = 0;
			if (v[0] == 0) {
				if (n == 1) total = c;
				else for (ll i = 1; i <= c; ++i) {
					if (v[1] != i) {
						v[0] = i;
						total += (b(1, i))%MOD;
						total %= MOD;
					}
				}
			}
			else {
				if (n == 1) total = 1;
				else total = b(1, v[0])%MOD;
			}
			cout << total << endl;
		}
	}
}
