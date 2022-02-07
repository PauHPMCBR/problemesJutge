#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll binExp(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b != 0) {
		if (b & 1) res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n == 2) cout << k << endl;
		else {
			ll counter = 0, result = 0;
			while (k > 0) {
				if (k%2) result = (result + binExp(n, counter))%mod;
				k /= 2;
				++counter;
			}
			cout << result << endl;
		}
	}
}