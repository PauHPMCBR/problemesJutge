#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m;
	cin >> n >> m;
	vector<ll>v(n);
	for (ll i = 0; i < n; ++i) {
		cin >> v[i];
		if (i != 0) v[i] += v[i-1];
	}
	ll a,b;
	while(m--){
		cin >> b >> a;
		if (b == 1) cout << v[a-1] << endl;
		else cout << v[a-1]-v[b-2] << endl;
	}
}