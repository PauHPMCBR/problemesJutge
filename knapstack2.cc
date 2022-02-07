#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll W,n;
vector<ll>v;
vector<ll>v2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> W;
	v = vector<ll>(n);
	v2 = vector<ll>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v2[i] >> v[i];
	}
	vector<ll>dp(W+1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = W; j >= 0; --j) {
			if (v2[i] <= j) {
				dp[j] = max(dp[j], dp[j-v2[i]] + v[i]);
			}
		}
	}
	cout << dp[W] << endl;
}