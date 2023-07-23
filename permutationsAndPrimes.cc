#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << 1 << endl;
		else if (n == 2) cout << "2 1" << endl;
		else {
			cout << 2 << ' ';
			for (int i = 1; i <= (n-3)/2; ++i) cout << i+3 << ' ';
			cout << 1 << ' ';
			for (int i = 1; i <= (n-2)/2; ++i) cout << (n-3)/2+3 + i << ' ';
			cout << 3 << ' ';
			cout << endl;
		}
	}
}