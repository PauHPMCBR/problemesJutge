#include <bits/stdc++.h>
using namespace std;
int n,m, start, ending, currentLevel;
vector<vector<int>>v;
vector<vector<char>>mapa;

bool shouldGo(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (v[x][y] <= currentLevel && v[x][y] != 0) return true;
	return false;
}

void update(int x, int y) {
	if (v[x][y] <= currentLevel) {
		mapa[x][y] = 'W';
		v[x][y] = 0;
		if (shouldGo(x-1,y)) update(x-1,y);
		if (shouldGo(x-1,y)) update(x-1,y);
		if (shouldGo(x-1,y)) update(x-1,y);
		if (shouldGo(x-1,y)) update(x-1,y);
	}
}

int main(){
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	mapa = vector<vector<char>>(n, vector<char>(m, ' '));
	char prov;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> prov;
			if (prov == '.') {
				mapa[i][j] = 'W';
			}
			else {
				v[i][j] = int(prov-'0');
			}
		}
	}
	cin >> start >> ending;
	for (int i = 0; i <= ending; ++i) {
		currentLevel = i;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				update(i,j);
			}
		}
		if (currentLevel >= start) {
			cout << "Sea level: " << currentLevel << endl;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cout << mapa[i][j];
				}
				cout << endl;
			}
		}
	}
}