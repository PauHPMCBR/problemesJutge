#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			if (i%2 == 1) cout << 2*n-i+1 << ' ';
			else cout << i << ' ';
		}
		cout << endl;
		for (int i = 2; i <= n; ++i) {
			if (i%2 == 1) cout << 2*n-i << ' ';
			else cout << i-1 << ' ';
		}
		cout << 2*n-1;
		cout << endl;
	}
}