#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll>v(m);
	vector<ll>pref(m+1, 0);
	ll c = 0;
	for (ll i = 0; i < m; ++i) {
		cin >> v[i];
		pref[i+1] = pref[i]+v[i];
	}
	ll start = 0;
	for(ll i = 1; i < m; ++i){
		while (v[i]-v[start] >= n && start < i-1) ++start;
		if (v[i]-v[start] >= n) continue;
		c += (i-start)*(n-v[i]) + pref[i] - pref[start];
	}
	cout << c << endl;
}