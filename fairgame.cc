#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,m,p,q;

vector<ll>a;
vector<ll>b;
ll sol(ll s, ll player) {
	if (s == 0) return (p-q);

	if (player == 1) {
		if (a[s] != -1) return a[s];
	}
	else if (b[s] != -1) return b[s];

	if (player == 1) {
		ll maxim = -1e17;
		for (int i = 1; i <= k && s-i >= 0; ++i) {
			maxim = max(maxim, (sol(s-i, -player) - (i%2)*m));
		}
		return a[s] = maxim;
	}
	else {
		ll minim = 1e17;
		for (int i = 1; i <= k && s-i >= 0; ++i) {
			minim = min(minim, (sol(s-i, -player) + (i%2)*m));
		}
		return b[s] = minim;
	}
}

int main(){
	cin >> n >> k >> m >> p >> q;
	a = vector<ll>(n+1, -1);
	b = vector<ll>(n+1, -1);
	cout << sol(n,1) << endl;
}