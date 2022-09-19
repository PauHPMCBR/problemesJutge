#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<ll>dp;
vector<vector<ll>>v(n);

ll b(ll pos, ll time) {
	if (pos == n) return 0;
	if (time > v[pos][0]) return b(pos+1, time);
	if (dp[pos] != -1) return dp[pos];
	return dp[pos] = max(b(pos+1, time), b(pos+1, v[pos][1])+v[pos][2]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		while (cin >> n) {
		dp = vector<ll>(n, -1);
		v = vector<vector<ll>>(n);
		for (ll i = 0; i < n; ++i) {
			ll d,w,b;
			cin >> d >> w >> b;
			v[i] = {d-w,d,b};
		}
		sort(v.begin(), v.end());
		cout << b(0, 0) << endl;
	}
}