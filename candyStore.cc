#include <bits/stdc++.h>
using namespace std;
#define int long long

int lcm(int x, int y) {
	return x * y / gcd(x,y);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		vector<int>b(n);
		int sol = 1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];

			int x = lcm(b[i], b[i-1]);
			if (a[i-1] % (x / b[i-1]) != 0 or a[i] % (x / b[i]) != 0) ++sol;
			else {
				int prov = a[i] * b[i];
				a[i] = x / b[i];
				b[i] = prov / a[i];
			}
		}
		cout << sol << endl;
	}
}