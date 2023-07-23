#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		int zeros = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] == 0) ++zeros;
		}
		int wrong = 0;
		for (int i = 0; i < zeros; ++i) {
			if (v[i] != 0) ++wrong;
		}
		
	}
}