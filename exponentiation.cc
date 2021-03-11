#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
typedef long long ll;
ll p(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b%2 != 0) return (p(a, b-1)*a)%MOD;
	ll x = (p(a, b/2))%MOD;
	return (x*x)%MOD;
}

int main(){
	ll n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << p(a, b) << endl;
	}
}