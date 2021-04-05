#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<ll>v(m);
		ll c = 0;
		for (ll i = 0; i < m; ++i) {
			cin >> v[i];
			
		}
		int start = 0;
		sort(v.begin(), v.end());
		for(ll i = 0; i < m; i++){
			for (ll j = start; j < i; ++j) {
				if (n+v[j]-v[i] > 0) c += n+v[j]-v[i];
				else if (start == j-1) ++start;
			}
		}
		cout << c << endl;
	}
}