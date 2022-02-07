#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000007;

ll p(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b%2 != 0) return (p(a, b-1)*a)%MOD;
	ll x = (p(a, b/2))%MOD;
	return (x*x)%MOD;
}

ll fact(ll a, ll b) {
	ll res = 1;
	for (ll i = a; i > b; --i) {
		res *= a;
		res %= MOD;
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	ll startEven = (4 * p(5, 2*n-1) * fact(2*n-1, 0))%MOD;
	ll startOdd = (5 * p(5, 2*n-1) * fact(2*n-1, 0))%MOD;
	cout << (startEven + startOdd)%MOD << endl;
}