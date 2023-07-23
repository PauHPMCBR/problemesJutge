#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		bool possible = false;
		for (int i = 1; i < n and !possible; ++i) {
			for (int j = 0; j < i; ++j) {
				if (__gcd(v[i], v[j]) < 3) {
					possible = true;
					break;
				}
			}
		}
		if (possible) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}