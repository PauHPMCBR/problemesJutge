#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, k, r, c;
	cin >> t;
	while (t--) {
		cin >> n >> k >> r >> c;
		vector<vector<int>>v1(n, vector<int>(n));
		vector<vector<int>>v2(n, vector<int>(n));
		int n1 = 0, n2 = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i+j -r-c+2) % k == 0) {
					v1[i][j] = true;
					++n1;
				}
				if ((i-j -r+c) % k == 0) {
					v2[i][j] = true;
					++n2;
				}
			}
		}

		//cout << n1 << ' ' << n2 << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (n1 <= n2) cout << (v1[i][j] ? 'X' : '.');
				else cout << (v2[i][j] ? 'X' : '.');
			}
			cout << endl;
		}
	}
}