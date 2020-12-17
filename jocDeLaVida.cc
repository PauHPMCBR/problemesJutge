#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <vector <char> > v;
vector <vector <char> > u;

char newValue(int x, int y) {
	int counter = 0;
	for (int i = -1; i < 2; ++i) {
		if (x+i < 0 || x+i >= n) continue;
		for (int j = -1; j < 2; ++j) {
			if (y+j < 0 || y+j >= m) continue;
			if (j == 0 && i == 0) continue;
				if (v[x+i][y+j] == 'B') ++counter;
		}
	}
	if (counter == 3) return 'B';
	if (v[x][y] == 'B') if (counter == 2) return 'B';
	return '.';
}

vector<vector <char>> update() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			u[i][j] = newValue(i, j);
	return u;
}

int main() {
	bool firstOne = true;
	while (cin >> n >> m) {
		if (n == 0) break;
		else {
			if (firstOne) firstOne = false;
			else cout << endl;
		}
		v = vector < vector <char> >(n, vector <char>(m));
		u = vector < vector <char> >(n, vector <char>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> v[i][j];
		
		v = update();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << v[i][j];
			}
			cout << endl;
		}
	}
}