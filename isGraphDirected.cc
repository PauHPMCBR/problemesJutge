#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	bool directed = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (v[i][j] != v[j][i]) directed = true;
		}
	}
	if (directed) cout << "YES" << endl;
	else cout << "NO" << endl;
}