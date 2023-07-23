#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == 1) {
			if (b == 2) cout << 3 << endl;
			else cout << 2 << endl;
		}
		else cout << 1 << endl;
	}
}