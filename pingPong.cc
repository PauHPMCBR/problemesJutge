#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<vector<ll>>v;
vector<ll>p2(32);
vector<ll>dp;

ll b(ll pos, ll used) {
	//	cout << pos << ' ';
	if (pos == n) return 0;
	if (dp[used] != -1) return dp[used];
	ll maxVal = 0;
	for (ll i = pos+1; i < n; ++i) {
		if (i == pos) continue;
		if ((used^p2[i]) > used) {
			used += p2[i];
			maxVal = max(maxVal, b(pos+1, used) + v[pos][i]);
			used -= p2[i];
		}
	}
	return dp[used] = maxVal;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	p2[0] = 1;
	for (ll i = 1; i <= 31; ++i) {
		p2[i] = p2[i-1]*2;
	}
	cin >> n;
	v = vector<vector<ll>>(n, vector<ll>(n));
	dp = vector<ll>(p2[n+1]+2, -1);
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}
	cout << b(0, 1) << endl;
}