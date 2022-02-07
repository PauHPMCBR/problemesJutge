#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binExp(ll a, ll b, ll mod) {
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
	ll t, a, b, mod;
	cin >> t;
	while (t--) {
		cin >> a >> b >> mod;
		cout << binExp(a, b, mod) << endl;
	}
}