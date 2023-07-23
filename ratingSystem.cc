#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int maxDecay = 0, k = 0;
		int currentPeak = 0;
		int elo = 0;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov;
			elo += prov;
			if (elo > currentPeak) currentPeak = elo;
			if (currentPeak - elo > maxDecay) {
				maxDecay = currentPeak - elo;
				k = currentPeak;
			}
		}
		cout << k << endl;
	}
}