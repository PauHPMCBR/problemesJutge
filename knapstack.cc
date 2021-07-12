#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,n;
vector<ll>v;
vector<vector<ll>>dp;

ll b(ll pos, ll val) {
	if (val > s) return 0;
	if (pos == n) return val;
	if (dp[pos][val] != -1) return dp[pos][val];
	return dp[pos][val] = max(b(pos+1, val), b(pos+1, val+v[pos]));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> n;
	dp = vector<vector<ll>>(n, vector<ll>(s+1, -1));
	v = vector<ll>(n);
	for (ll i = 0; i < n; ++i) cin >> v[i];
	cout << b(0, 0) << endl;
}