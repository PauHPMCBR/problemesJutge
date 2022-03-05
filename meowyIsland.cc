#include <bits/stdc++.h>
using namespace std;
int n, m, floodLevel = 0;
vector<vector<int>>mapa;
vector<vector<bool>>v;
vector<vector<bool>>v2;
vector<vector<bool>>resetVec;
vector<vector<bool>>updated;

bool isValid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void update(int x, int y, int f) {
	if (v2[x][y] == 0 && v[x][y] == 0) return;
	if (updated[x][y]) return;
	updated[x][y] = true;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (isValid(x+i, y+j)) {
				if (f) {
					if (mapa[x+i][y+j] <= floodLevel) {
						v[x+i][y+j] = 1;
						update(x+i, y+j, f);
					}
				}
				else {
					if (mapa[x+i][y+j] <= floodLevel) {
						v2[x+i][y+j] = 1;
						update(x+i, y+j, f);
					}
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	mapa = vector<vector<int>>(n, vector<int>(m, -1));
	v = vector<vector<bool>>(n, vector<bool>(m, 1));
	v2 = vector<vector<bool>>(n, vector<bool>(m, 0));
	resetVec = vector<vector<bool>>(n, vector<bool>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char prov;
			cin >> prov;
			if (prov != '.') {mapa[i][j] = prov-'0'; v[i][j] = 0;}
		}
	}
	int s, e;
	cin >> s >> e;
	for (; floodLevel <= e; ++floodLevel) {
		if (floodLevel%2) v = resetVec;
		else v2 = resetVec;
		updated = resetVec;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				update(i, j, floodLevel%2);
			}
		}
		if (floodLevel >= s) {
			cout << "Sea level: " << floodLevel << endl;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (floodLevel%2) {
						cout << (v[i][j] ? 'W' : ' ');
					}
					else {
						cout << (v2[i][j] ? 'W' : ' ');
					}
				}
				cout << endl;
			}
		}
	}
}