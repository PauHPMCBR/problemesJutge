#include <bits/stdc++.h>
using namespace std;

vector<vector <char>>v;
int f, c;

bool isValid(int x, int y) {
	if (x < 0 || x >= f) return false;
	if (y < 0 || y >= c) return false;
	if (v[x][y] == '*') return false;
	return true;
}

int pathfind(int x, int y, int bpress) {
	if (y == c-1) return bpress; //o/
	//v[x][y] = bpress; DYNAMIC PROGRAMING
	int min = -1;
	int prov;
	if (isValid(x-1, y+1)) {
		if (v[x-1][y+1] == 'T') prov = pathfind(x-1, y+1, bpress+4);
		else prov = pathfind(x-1, y+1, bpress+1);
		if (min > prov || min == -1) min = prov;
	}
	if (isValid(x, y+1)) {
		if (v[x][y+1] == 'T') prov = pathfind(x, y+1, bpress+3);
		else prov = pathfind(x, y+1, bpress);
		if (min > prov || min == -1) min = prov;
	}
	if (isValid(x+1, y+1)) {
		if (v[x+1][y+1] == 'T') prov = pathfind(x+1, y+1, bpress+4);
		else prov = pathfind(x+1, y+1, bpress+1);
		if (min > prov || min == -1) min = prov;
	}
	return min;
}

int main(){
	int x, y;
	cin >> c >> f;
	v = vector<vector <char>>(f, vector<char>(c));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'M') {x = i; y = j;}
		}
	}
	int res = pathfind(x, y, 0);
	if (res == -1) cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
}