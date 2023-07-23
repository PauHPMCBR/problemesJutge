#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, m;
	cin >> t;
	while (t--) {
		cin >> m;
		vector<vector<int>>v(m);
		vector<int>sol(m, -1);
		vector<int>used(50001);
		for (int i = 0; i < m; ++i) {
			int n;
			cin >> n;
			v[i] = vector<int>(n);
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
			}
		}

		for (int i = m-1; i >= 0; --i) {
			for (int j = 0; j < v[i].size(); ++j) {
				if (!used[v[i][j]]) sol[i] = v[i][j];
				used[v[i][j]] = true;
			}
		}

		bool exist = true;
		for (int i = 0; i < m; ++i) if (sol[i] == -1) {exist = false; break;}
		if (!exist) cout << -1 << endl;
		else {
			for (int i : sol) cout << i << ' ';
			cout << endl;
		}
	}
}