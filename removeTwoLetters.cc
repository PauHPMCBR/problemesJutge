#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		int res = n-1;

		if (s[0] == s[2]) --res;
		
		for (int i = 3; i < n; ++i) {
			if (s[i-2] == s[i]) --res;
			else {
				if (i%2) if (s[i] == s[i-2] and s[i-1] == s[i-3]) --res;
				else if (s[i] == s[i-2] and s[i-1] == s[i-3]) --res;
			}
		}


		cout << max(res, 1LL) << '\n';
	}
}