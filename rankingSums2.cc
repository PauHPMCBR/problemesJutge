#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll k, n;
	while (cin >> k >> n) {
		vector<ll>v(n);
		vector<ll>ps(n);
		cin >> v[0];
		ps[0] = v[0];
		for (ll i = 1; i < n; ++i) {
			cin >> v[i];
			ps[i] = ps[i-1]+v[i];
		}
		
	}
}