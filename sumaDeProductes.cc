#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll>v;
vector<ll>dp;

ll b(ll pos) {
	if (pos == n) return 0;
	if (dp[pos] != -1) return dp[pos];
	dp[pos] = b(pos+1)+v[pos];
	if (pos < n-1) dp[pos] = max(dp[pos], b(pos+2) + v[pos]*v[pos+1]);
	if (pos < n-2) dp[pos] = max(dp[pos], b(pos+3) + v[pos]*v[pos+1]*v[pos+2]);
	return dp[pos];
}

int main(){
	while (cin >> n) {
		v = vector<ll>(n);
		dp = vector<ll>(n, -1);
		for (ll i = 0; i < n; ++i) cin >> v[i];
		cout << b(0) << endl;
	}
}