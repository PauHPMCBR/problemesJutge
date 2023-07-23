#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, y;
	while (cin >> n >> m >> x >> y) {
		if (n > m) {
			swap(n, m);
			swap(x, y);
		}
		int ans = 2*n;
		if (abs(x - n) < 2) ans -= 2;
		cout << ans << endl;
	}
}