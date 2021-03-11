#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t, n, m, a;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		set<pair<ll,ll>>s;
		vector<vector<bool>>v(n, vector<bool>(m, true));
		for (ll i = 1; i < n+1; ++i) {
			cin >> a;
			for (int j = 1; j <= a; ++j) s.insert({i,j});
		}
		ll count = n;
		for (ll i = 1; i < m+1; ++i) {
			cin >> a;
			int cond = 0;
			bool mobe = true;
			for (int j = 1; j <= a; ++j) if (s.count({j,i})) {
				if (mobe) mobe = false;
			}

		}
	}
}