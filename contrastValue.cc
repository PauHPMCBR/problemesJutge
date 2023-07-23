#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, contrast = 0;
		cin >> n;
		vector<int>v(n);
		cin >> v[0];
		for (int i = 1; i < n; ++i) {
			cin >> v[i];
			contrast += abs(v[i-1] - v[i]);
		}
		if (n == 1 or contrast == 0) cout << 1 << endl;
		else if (n == 2 or contrast == abs(v[0] - v[n-1])) cout << 2 << endl;
		else {
			int rem = 0;
			int i1 = 0, i2 = 1;
			while (i2 < n-1) {
				if (abs(v[i1] - v[i2]) + abs(v[i2] - v[i2+1]) == abs(v[i1] - v[i2+1])) {
					++rem;
				}
				else {
					i1 = i2;
				}
				++i2;
			}

			cout << n-rem << endl;
		}
	}
}