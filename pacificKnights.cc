#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		if (m > n) swap(n, m);
		if (m == 1) cout << n;
		else if (m == 2) {
			if (n%4 == 0) cout << n;
			else if (n%4 == 1) cout << n+1;
			else if (n%4 == 2) cout << n+2;
			else if (n%4 == 3) cout << n+1;
		}
		else cout << (n*m+1)/2;
		cout << endl;
	}
}