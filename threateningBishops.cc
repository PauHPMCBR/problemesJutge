#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool>>v;

void diag(int x, int y, int a, int b) {
	int i = a, j = b;
	while (x+i < n and x+i >= 0 and y+j < m and y+j >= 0) {
		if (v[x+i][y+j]) {
			cout << '(' << x+1 << ',' << y+1 << ")<->(" << x+i+1 << ',' << y+j+1 << ')' << endl;
			return;
		}
		i += a;
		j += b;
	}
}

int main() {
	cin >> n >> m;
	v = vector<vector<bool>>(n, vector<bool>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == 'X') v[i][j] = true;
		}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) {
				diag(i,j,1,1);
				diag(i,j,1,-1);
				diag(i,j,-1,1);
				diag(i,j,-1,-1);
			}
		}
	}

}