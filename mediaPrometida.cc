#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t;
	while (cin >> t) {
		ll s = 0, m;
		if (t == 0) return 0;
		for (ll i = 0; i < t; ++i) {
			ll prov;
			cin >> prov;
			s += prov;
		}
		cin >> m;
		m *= (t+1);
		//cout << "m: " << m << " s: " << s << endl;
		if (m-s > 10 || m-s < 0) cout << "IMPOSIBLE" << endl;
		else cout << m-s << endl;
	}
}