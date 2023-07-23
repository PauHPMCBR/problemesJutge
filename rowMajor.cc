#include <bits/stdc++.h>
using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<bool>>v(n, vector<bool>(26, 0));
		vector<int>factors;
		for (int i = 1; i*i <= n; ++i) {
			if (n%i == 0) {
				factors.push_back(i);
				if (i*i != n) factors.push_back(n/i);
			}
		}

		for (int i = 0; i < n; ++i) {
			int ans = 0;
			for (int j = 0; j < 26; ++j) if (v[i][j] == 0) {ans = j; break;}
			cout << char('a' + ans);
			for (int x : factors) if (i+x < n) v[i+x][ans] = 1;
		}
		
		cout << endl;
	}
}