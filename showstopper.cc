#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		vector<int>b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		bool p = true;
		int m1 = a[n-1], m2 = b[n-1];
		if (m1 < m2) swap(m1, m2);

		for (int i = 0; i < n and p; ++i) {
			if (max(a[i], b[i]) > m1 or min(a[i], b[i]) > m2) p = false;
		}
		cout << (p ? "Yes" : "No") << endl;
	}
}