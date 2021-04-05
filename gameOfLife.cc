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
				if (v[x+i][y+j] == '#') ++counter;
		}
	}
	if (counter == 3) return '#';
	if (v[x][y] == '#') if (counter == 2) return '#';
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
	int it;
	cin >> it >> n;
	m = n;
	v = vector < vector <char> >(n, vector <char>(m));
	u = vector < vector <char> >(n, vector <char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	while (it--) v = update();
	for (int i = 0; i < n; ++i) {
		bool space = true;
		for (int j = 0; j < m; ++j) {
			if (space) space = false;
			else cout << ' ';
			cout << v[i][j];
		}
		cout << endl;
	}
}