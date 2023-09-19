#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<bool>>v(n, vector<bool>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char c;
				cin >> c;
				v[i][j] = (c == '1');
			}
		}

		int lines = 0;
		for (int i = 1; i < n; ++i) {
			bool drawingLine = false;
			for (int j = 0; j < m; ++j) {
				if (v[i-1][j] && v[i][j]) {
					if (!drawingLine) {
						drawingLine = true;
						++lines;
					}
				}
				else {
					if (drawingLine) drawingLine = false;
				}
			}
		}

		for (int j = 1; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (v[i][j-1] && v[i][j]) ++lines;
			}
		}
		//cout << lines << endl;
		cout << (lines%2 ? "Mirko" : "Slavko") << endl;
	}
}