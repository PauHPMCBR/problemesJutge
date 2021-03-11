#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main(){
	int n;
	cin >> n;
	vector<vector<ll>>v(n, vector<ll>(n, 0));
	char prov;
	v[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> prov;
			if (i == 0 && j == 0) if (prov == '*') {cout << 0 << endl; return 0;}
			if (prov == '*') v[i][j] = -1;
			else {
				if (i > 0) if (v[i-1][j] != -1) v[i][j] += v[i-1][j];
				if (j > 0) if (v[i][j-1] != -1) v[i][j] += v[i][j-1];
			}
			v[i][j] %= mod;
		}
	}
	if (v[n-1][n-1] == -1) cout << 0 << endl;
	else cout << v[n-1][n-1] << endl;
}