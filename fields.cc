#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>>v(n+1, vector<int>(m+1));
		int growings = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> v[i][j];
				if (v[i][j] != 0) 
					if (v[i][j] != v[i-1][j] and v[i][j] != v[i][j-1]) ++growings;
			}
		}
		cout << growings << endl;
	}
}