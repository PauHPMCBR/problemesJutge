#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<vector<bool>>v(n, vector<bool>(m, 0));
		vector<vector<bool>>used(n, vector<bool>(m, 0));
		int toCheck = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char prov;
				cin >> prov;
				if (prov == '*') v[i][j] = true;
				++toCheck;
			}
		}
		bool possible = true;
		int x = n-1, y = 0;
		while (!(x == 0 && y == m)) {
			if (y == m) {
				y = 0;
				--x;
				continue;
			}
			if (v[x][y]) {
				int x1 = x-1, y1 = y-1, y2 = y+1;
				int tickS = 1;
				while(true) {
					if (x1 < 0 || y1 < 0 || y2 >= m) break;
					if (v[x1][y1] && v[x1][y2]) {
						++tickS;
						--x1; --y1; ++y2;
					}
					else break;
				}
				if (tickS > k) {
					used[x][y] = true;
					x1 = x-1, y1 = y-1, y2 = y+1;
					for (int i = 1; i < tickS; ++i) {
						used[x1][y1] = true;
						used[x1][y2] = true;
						--x1; --y1; ++y2;
					}
				}

				if (!used[x][y]) {
					possible = false;
					break;
				}
			}
			++y;
		}
		cout << (possible ? "YES" : "NO") << endl;
	}
}