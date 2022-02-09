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

ll comb(ll n, ll m) {
	return (((fac[n]*inv[m])%mod)*inv[n-m])%mod;
}
ll vari(ll n, ll m) {
	return (fac[n]*inv[n-m])%mod;
}
ll cRep(ll n, ll m) {
	return comb(n+m-1,m);
}
ll pRep(ll n, ll m) {
	return (fac[n]*inv[n-m])%mod;
}


int main(){
	fac[0] = 1, inv[0] = 1;
	for (ll i = 1; i < 2*1e6+1; ++i) {
		fac[i] = (fac[i-1]*i)%mod;
		inv[i] = exp(fac[i], mod-2);
	}
	
	ll n;
	cin >> n;
	string s;
	cin >> s;

	if (n%2) {cout << 0 << endl; return 0;}

	ll x = 0, y = 0;
	bool possible = true;
	for (char c : s) {
		if (c == '(') ++x;
		else ++y;
		if (x-y < 0) {possible = false; break;}
	}
	if (x > n/2) possible = false;
	if (x == n/2) {cout << 1 << endl; return 0;}
	if (!possible) {cout << 0 << endl; return 0;}
	ll k = n - s.size() - x-y;
	
	//cout << (((comb(k, k/2)*exp(k/2+1, mod-2))%mod)*cRep(k/2+1, x-y))%mod << endl;
	ll res =  fac[n-s.size()]*inv[n/2-x]%mod * inv[n/2-y]%mod;
	res -= fac[n-s.size()]*inv[n/2-x-1]%mod * inv[n/2-y+1]%mod;
	cout <<  (res+mod)%mod << endl;
}