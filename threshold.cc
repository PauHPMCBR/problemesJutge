#include <bits/stdc++.h>
using namespace std;
int n,m;
int mobe;
vector<vector<int>>v;
vector<vector<int>>img;

void makePixel(int x, int y, int range) {
	int mean = 0;
	for (int i = x-range; i <= x+range; ++i) {
		for (int j = y-range; j <= y+range; ++j) {
			if (i < 0 || i >= n) continue;
			if (j < 0 || j >= m) continue;
			mean += v[i][j];
		}
	}
	if (int(mean/mobe) <= v[x][y]) img[x][y] = 1;
}

int main(){
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	img = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	int range;
	cin >> range;
	mobe = range*range;
	range = (range-1)/2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			makePixel(i,j,range);
		}
	}
	for (int i = 0; i < n; ++i) {
		bool espai = true;
		for (int j = 0; j < m; ++j) {
			if (espai) espai = false;
			else cout << ' ';
			cout << img[i][j];
		}
		cout << endl;
	}
}