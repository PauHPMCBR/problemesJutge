#include <iostream>
#include <vector>
using namespace std;



int main() {
	int n;
	bool first = true;
	while (cin >> n) {
		if (first) first = false;
		else cout << endl;
		vector<vector<vector<int>>>v(n, vector<vector<int>>(n, vector<int>(n)));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					cin >> v[i][j][k];
				}
			}
		}

		vector<int>line(n+1);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					for (int a = -1; a < 2; ++a) {
						for (int b = -1; b < 2; ++b) {
							for (int c = -1; c < 2; ++c) {
								if (not (a == 0 and b == 0 and c == 0)) {
									for (int dist = 1; i+dist*a >= 0 and i+dist*a < n and j+dist*b >= 0 and j+dist*b < n and k+dist*c >= 0 
										and k+dist*c < n and v[i+dist*a][j+dist*b][k+dist*c] == v[i][j][k]; ++dist) ++line[dist+1];
								}
							}
						}
					}
				}
			}
		}

		for (int i = 2; i <= n; ++i) {
			if (line[i] != 0) cout << "Ratlles de mida " << i << ": " << line[i]/2 << endl;
		}
	}
}