#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int>v(n);
	vector<int>v2(n);
	vector<int>dp(x+1, 0);
	for (int i = 0; i < n; ++i) cin >> v2[i];
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		
		for (int j = x; j >= 0; --j) {
			if (v2[i] <= j) {
				dp[j] = max(dp[j], dp[j-v2[i]] + v[i]);
			}
		}
	}
	cout << dp[x] << endl;
}