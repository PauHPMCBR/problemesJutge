#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int mod = 998244353;
	int n, a1, x, y, m, k;
	cin >> n >> a1 >> x >> y >> m >> k;

	vector<vector<int>>b(n+1, vector<int>(k+1));
	vector<int>a(n+1);
	a[1] = a1;
	b[1][0] = a[1];
	b[1][1] = a[1]; //or 1?
	int sum = a[1];
	for (int i = 2; i <= n; ++i) {
		a[i] = (a[i-1]*x + y)%m;
		sum += a[i];
		sum %= mod;
		b[i][1] = (b[i-1][1] + sum) % mod;
	}


	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			b[i][j] = b[i-1][j-1] + b[i-1][j];
			//if (i > j) b[i][j] += a[i-j+1];
			b[i][j] %= mod;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res ^= i*b[i][k];
	}
	cout << res << endl;


	/*for (auto i : a) cout << i << ' ' ;
		cout << endl;
	cout << endl;

	for (auto i : b) {
		for (auto j : i) cout << j <<' ';
		cout << endl;
	}
	cout << endl;*/

}