#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>X(202,vector<int>(202,0));
	vector<vector<int>>Y(202,vector<int>(202,0));
	vector<vector<int>>Z(202,vector<int>(202,0));
	int repX = 0, repY = 0, repZ = 0;
	while (n--) {
		int x,y,z;
		cin >> x >> y >> z;
		x += 100; y += 100; z += 100;
		++X[y][z];
		++Y[x][z];
		++Z[x][y];
		if (X[y][z] == 1) ++repX;
		if (Y[x][z] == 1) ++repY;
		if (Z[x][y] == 1) ++repZ;
	}
	if (repX >= repY) {
		if (repX >= repZ) cout << 'X' << endl;
		else {
			if (repY >= repZ) cout << 'Y' << endl;
			else cout << 'Z' << endl;
		}
	}
	else {
		if (repY >= repZ) cout << 'Y' << endl;
		else cout << 'Z'<< endl;
	}
}