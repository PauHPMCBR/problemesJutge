#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<vector<pair<int,int>>>dp;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> k) {
		//menor i major valor al utilitzar n numeros amb k separadors
		dp = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>(k+1, {-1,-1}));
		dp[0][0] = {0,0};
		
		for (int j = 0; j <= k; ++j) {
			for (int i = 1; i <= n; ++i) {
				int sum = 0;
				for (int x = i-1; x >= 0; --x) {
					sum += x;
					dp[i][j].first =
				}
			}
		}

		cout << "----------" << endl;
	}
}