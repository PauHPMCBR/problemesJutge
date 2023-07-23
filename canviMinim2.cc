#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, n;
	while (cin >> c >> n) {
		vector<int>m(n);
		for (int i = 0; i < n; ++i) cin >> m[i];
		vector<int>dp(c+1, -1);
		dp[0] = 0;
		for (int i = 0; i <= c; ++i) {
			if (dp[i] == -1) continue;
			for (int moneda : m) {
				if (i + moneda > c) continue;
				if (dp[i+moneda] == -1 or dp[i+moneda] > dp[i]+1)
					dp[i+moneda] = dp[i] + 1;
			}
		}
		if (dp[c] == -1) cout << "no" << endl;
		else cout << dp[c] << endl;
	}
}