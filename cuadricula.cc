#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<vector<int>>v(n, vector<int>(m, 0));
		ll sum = 0;
		char c;
		int x, s;
		while (k--) {
			cin >> c >> x >> s;
			--x;
			if (c == 'C') {
				for (int i = 0; i < n; ++i) {
					sum -= v[i][x];
					v[i][x] = s;
					sum += s;
				}
			}
			else {
				for (int i = 0; i < m; ++i) {
					sum -= v[x][i];
					v[x][i] = s;
					sum += s;
				}
			}
		}
		cout << sum << endl;
	}
}