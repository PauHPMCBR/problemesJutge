#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>>v(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> v[i][j];
			}
		}
		int a, b;
		cin >> a >> b;
		bool increasing = true;
		int k = 1, last = v[a][b];
		while (increasing and a+k < n and b+k < m) {
			if (v[a+k][b+k] > last) {
				last = v[a+k][b+k];
				++k;
			}
			else increasing = false;
		}

		k = 1, last = v[a][b];
		while (increasing and a-k >= 0 and b+k < m) {
			if (v[a-k][b+k] > last) {
				last = v[a-k][b+k];
				++k;
			}
			else increasing = false;
		}

		k = 1, last = v[a][b];
		while (increasing and a+k < n and b-k >= 0) {
			if (v[a+k][b-k] > last) {
				last = v[a+k][b-k];
				++k;
			}
			else increasing = false;
		}

		k = 1, last = v[a][b];
		while (increasing and a-k >= 0 and b-k >= 0) {
			if (v[a-k][b-k] > last) {
				last = v[a-k][b-k];
				++k;
			}
			else increasing = false;
		}

		cout << (increasing ? "yes" : "no") << endl;
	}
}