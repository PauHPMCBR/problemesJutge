#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, q;
	cin >> n >> q;
	vector<ll>v(n);
	cin >> v[0];
	for (ll i = 1; i < n; ++i) {
		cin >> v[i];
		v[i] += v[i-1];
	}
	while (q--) {
		ll pos;
		cin >> pos;
		cout << distance(v.begin(), lower_bound(v.begin(), v.end(), pos))+1 << endl;
	}
}