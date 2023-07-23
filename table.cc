#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int mx1 = -1e8, mx2 = -1e8, mn1 = 1e8, mn2 = 1e8;
		for (int i = 0; i < n*m; ++i) {
			int prov;
			cin >> prov;
			if (prov >= mx1) {
				mx2 = mx1;
				mx1 = prov;
			}
			else if (prov > mx2) mx2 = prov;

			if (prov <= mn1) {
				mn2 = mn1;
				mn1 = prov;
			}
			else if (prov < mn2) mn2 = prov;
		}

		if (abs(mx1 - mx2) < abs(mn1 - mn2)) {
			swap(mx1, mn1);
			swap(mx2, mn2);
		}
		if (n > m) swap(n, m);

		int sol = mx1 * (n*m - 1);
		sol -= mn2 * (n - 1);
		sol -= mn1 * (m*n - 1 - n + 1);

		cout << abs(sol) << endl;
	}
}