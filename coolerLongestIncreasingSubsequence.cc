#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> dp(n+1, 1e9+1);
    dp[0] = -(1e9+1);

    for (int i = 0; i < n; ++i) {
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (dp[j-1] < v[i] && v[i] < dp[j]) dp[j] = v[i];
	}

    for (int i = n; i >= 0; --i) {
        if (dp[i] != 1e9+1) {
        	cout << i << endl;
        	return 0;
        }
            
    }
}