#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<vector<ll>>v(n);


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		while (cin >> n) {
		v = vector<vector<ll>>(n);
		for (ll i = 0; i < n; ++i) {
			ll d,w,b;
			cin >> d >> w >> b;
			v[i] = {d,w,b};
		}
		sort(v.begin(), v.end());
		map<ll,ll>m;
		m[0] = 0;
		ll sol = 0;
		for (ll i = 0; i < n; ++i) {
			ll t = v[i][0];
			m[-t] = max((*m.lower_bound(-(t - v[i][1]))).second + v[i][2], (*m.lower_bound(-t)).second);
			sol = m[-t];
		} 
		cout << sol << endl;
	}
}