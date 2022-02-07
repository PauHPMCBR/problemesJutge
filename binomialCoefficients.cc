#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
vector<ll>factorials(1e6+5);

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
	ll t, n, m;
	factorials[0] = 1;
	for (int i = 1; i < 1e6+1; ++i) {
		factorials[i] = (factorials[i-1]*i)%mod;
	}
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (m > n) cout << 0 << endl;
		else if (m == n) cout << 1 << endl;
		else cout << (((factorials[n] * binExp(factorials[m], mod-2))%mod) * binExp(factorials[n-m], mod-2))%mod << endl;
	}
}