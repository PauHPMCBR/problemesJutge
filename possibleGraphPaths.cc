#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<set<ll>>v;
map<set<ll>,ll>dp;

ll b(set<ll> s) {
	if (dp.count(s)) return dp[s];
	if (s.size() == 1) return dp[s] = 1;
	for (auto i : s) {
		set<ll>prov(s);
		set<ll>prov2(v[i]);
		prov.erase(i);
		prov.insert(prov2.begin(), prov2.end());
		dp[s] += b(prov);
	}
	return dp[s];
}


int main(){
	ll n,m;
	cin >> n >> m;
	v = vector<set<ll>>(n);
	while (m--) {
		ll a,b;
		cin >> a >> b;
		v[a].insert(b);
	}
	cout << b(v[0]) << endl;
}