#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll>v(n);
		for (ll i = 0; i < n; ++i) {
			cin >> v[i];
		}

		ll last = -2, changes = 0;
		for (ll i = 1; i < n; ++i) {
			if (v[i] == v[i-1]) continue;
			if (last == -2) {
				if (v[i] > v[i-1]) last = 1;
				else last = -1;
			}
			if (v[i] > v[i-1]) {
				if (last != 1) {
					++changes;
					last = 1;
				}
			}
			else {
				if (last != -1) {
					++changes;
					last = -1;
				}
			}
		}
		cout << (changes)/2 << endl;
	}
}