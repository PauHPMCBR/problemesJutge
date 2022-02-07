#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			cin >> v[i][j];
			if (i == 0) {
				if (j == 0) continue;
				v[i][j] = v[i][j-1] + v[i][j];
			}
			else {
				int maxim = v[i-1][j];
				if (j != 0) maxim = max(maxim, v[i][j-1]);
				v[i][j] = maxim + v[i][j];
			}
		}
	}
	cout << v[n-1][m-1] << endl;
}