#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
vector<ll>fac(2*1e6+1);
vector<ll>inv(2*1e6+1);

ll exp(ll n, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p&1) res = (res*n)%mod;
		p /= 2;
		n = (n*n)%mod;
	}
	return res;
}


int main(){
	fac[0] = 1, inv[0] = 1;
	for (ll i = 1; i < 2*1e6+1; ++i) {
		fac[i] = (fac[i-1]*i)%mod;
		inv[i] = exp(fac[i], mod-2);
	}

	ll n, m;
	cin >> n >> m;
	ll res = fac[n+m-1];
	res *= inv[m];
	res %= mod;
	res *= inv[n-1];
	cout << res%mod << endl;
}