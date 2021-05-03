#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll res = 0;
	for (ll i = n; i <= m; ++i) res += i;
	ll prov;
	for (ll i = 1; i <= (m-n); ++i) {
		cin >> prov;
		res -= prov;
		cout << res << endl;
	}
	cout << res << endl;
}