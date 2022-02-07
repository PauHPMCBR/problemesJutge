#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, x;
	cin >> n >> x;
	vector<ll>v(n);
	vector<ll>dp(x+1, 0);
	for (ll i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	dp[0] = 1;
	for (ll i = 0; i < n; ++i) {
		for (ll pos = 0; pos+v[i] <= x; ++pos) {
			if (dp[pos] == 0) continue;
			dp[pos+v[i]] += dp[pos];
			//if (dp[pos+v[i]] >= mod) dp[pos+v[i]] -= mod;
			dp[pos+v[i]] %= mod;
		}
	}
	cout << dp[x] << endl;
}
