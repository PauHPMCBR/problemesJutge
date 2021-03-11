#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<pair<ll,ll>>v(n+1);
		//vector<pair<ll,ll>>w(5*1e5+2);
		ll prov;
		for (ll i = 1; i <= n; ++i) {
			cin >> prov;
			v[i] = {prov, i};
			//w[prov] = {i, i};
		}
		ll c = n;
		for (ll j = 1; j <= m; ++j) {
			ll color = -1;
			cin >> prov;
			for (ll i = 1; i <= prov && i <= n; ++i) {
				if (v[i].first >= j) {
					if (color == -1) color = v[i].second;
					else {
						if (v[i].second != color) {
							v[i].second = color;
							--c;
						}
					}
				}
			}
			if (color == -1) ++c;
		}
		cout << c << endl;
	}
}