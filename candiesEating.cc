#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll block = 300;
ll n;
vector<ll>toSub;
vector<ll>minBlock;
vector<ll>v;

void build(ll id) {
	ll l = block*id;
	ll r = min(l+block-1, n-1);
	toSub[id] = 0;
	minBlock[id] = 1e9+5;
	for (ll i = l; i <= r; ++i) {
		if (v[i] != 0) minBlock[id] = min(minBlock[id], v[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin >> n >> q;
	toSub = vector<ll>(n/block+3);
	minBlock = vector<ll>(n/block+3);
	vector<ll>sol(n, -1);
	v = vector<ll>(n);
	for (ll i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (ll i = 0; i <= (n-1)/block; ++i) build(i);
	for (ll index = 1; index <= q; ++index) {
		ll l, r, x;
		cin >> l >> r >> x;
		--l; --r;
		ll lb = l/block, rb = r/block;
		for (ll id = lb; id <= rb; ++id) {
			ll l2 = id*block;
			ll r2 = min(l2+block-1, n-1);
			if (l <= l2 && r2 <= r) {
				if (minBlock[id] <= x) {
					toSub[id] += x;
					for (ll j = l2; j <= r2; ++j) {
						if (v[j]) {
							v[j] -= toSub[id];
							if (v[j] < 0) v[j] = 0;
							if (!v[j]) sol[j] = index;
						}
					}
					build(id);
				}
				else {
					minBlock[id] -= x;
					toSub[id] += x;
				}
			}
			else {
				for (ll j = l2; j <= r2; ++j) {
					if (v[j] > 0) v[j] -= toSub[id];
				}
				for (ll pos = max(l, l2); pos <= min(r, r2); ++pos) {
					if (v[pos] > 0) {
						v[pos] -= x;
						if (v[pos] < 0) v[pos] = 0;
						if (!v[pos]) sol[pos] = index;
					}
				}
				build(id);
			}
		}
	}
	for (auto i : sol) cout << i << " ";
	cout << endl;
}