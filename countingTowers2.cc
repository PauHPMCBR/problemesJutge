#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t, n;
	vector<ll>dp(1e6+5, -1);
	vector<ll>p3(1e6+5);
	p3[0] = 1;
	dp[0] = 1;
	dp[1] = 2;
	for (ll i = 1; i < 1e6+5; ++i) {
		p3[i] = p3[i-1]*3;
		if (p3[i] >= mod) p3[i] -= mod;
	}
	cin >> t;
	ll pos = 1;
	while (t--) {
		cin >> n;
		while (pos <= n) {
			dp[pos] = 1 + p3[pos-1];
			for (ll i = 1; i < pos; ++i) {
				dp[pos] += (1+p3[i-1]) * dp[pos-i];
				dp[pos] %= mod;
			}
			++pos;
		}
		cout << dp[n] << endl;
	}
}