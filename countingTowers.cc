#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

vector<ll>bp(1e6+5, -1);
vector<ll>p2(1e6+5, -1);

ll b(ll s) {
	if (bp[s] != -1) return bp[s];
	ll res = 0;
	for (int i = 1; i < s; ++i) {
		res += b(s-i) + a(s-i) * a(s-i);
		res %= mod;
	}
	return bp[s] = res;
}

int main(){
	ll t, n;
	bp[1] = 3;
	bp[0] = 0;
	p2[0] = 1;
	for (ll i = 1; i < 1e6+5; ++i) {
		p2[i] = p2[i-1]*2;
		p2[i] %= mod;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << b(n+1) << endl;
		cout << "b ";
		int prov = 1;
		while (bp[prov] != -1) {
			cout << bp[prov] << ' ';
			++prov;
		}
		cout << endl;
	}
}