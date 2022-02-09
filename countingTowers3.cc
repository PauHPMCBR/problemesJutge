#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll t, n;
vector<ll>dp(1e6+5, -1);

ll b(ll x) {
	if (dp[x] != -1) return dp[x];
	return dp[x] = ((6*b(x-1)+15*mod) - 7*b(x-2))%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 2;
	dp[2] = 8;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << b(n) << endl;
	}
}