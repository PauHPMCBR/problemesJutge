#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll W,n;
vector<ll>v;
vector<ll>v2;
vector<vector<ll>>dp;

ll b(ll pos, ll weight, ll val) {
	if (weight > W) return 0;
	if (pos == n) return val;
	if (dp[pos][weight] != -1) return dp[pos][weight];
	return dp[pos][weight] = max(b(pos+1, weight, val), b(pos+1, weight+v2[pos], val+v[pos]));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> W;
	dp = vector<vector<ll>>(n, vector<ll>(W+1, -1));
	v = vector<ll>(n);
	v2 = vector<ll>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v2[i] >> v[i];
	}
	cout << b(0, 0, 0) << endl;
}