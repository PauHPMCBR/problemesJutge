#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int sum = 0;
		bool b = true;
		for (int i = 1; i < n; ++i) {
			if (n%i == 0) sum += i;
			else if (i > sum) {b = false; break;}
		}
		cout << (b ? "yes" : "no") << endl;
	}
}