#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9+7;

int main(){
	ll n;
	cin >> n;
	ll v[n][n][n];
	v[0][0][0] = 1;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			for (ll k = 0; k < n; ++k) {
				if (i == 0 && j == 0 && k == 0) continue;
				v[i][j][k] = 0;
				if (i > 0) v[i][j][k] += v[i-1][j][k];
				if (j > 0) v[i][j][k] += v[i][j-1][k];
				if (k > 0) v[i][j][k] += v[i][j][k-1];
				v[i][j][k] %= m;
			}
		}
	}
	cout << v[n-1][n-1][n-1] << endl;
}