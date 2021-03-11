#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000006;
typedef long long ll;
ll p(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b%2 != 0) return (p(a, b-1)*a)%MOD;
	ll x = (p(a, b/2))%MOD;
	return (x*x)%MOD;
}

int main(){
	ll n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		MOD = 1000000006;
		int d = p(b,c);
		MOD = 1000000007;
		cout << p(a, d) << endl;
	}
}