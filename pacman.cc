#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>v;
vector<string>v2;

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

bool dfs(int x, int y) {
	if (v[x][y] == -1) return false;
	v[x][y] = -1;
	if (v2[x][y] == 'B') return true;
	if (isValid(x+1,y) && dfs(x+1,y)) return true;
	if (isValid(x-1,y) && dfs(x-1,y)) return true;
	if (isValid(x,y+1) && dfs(x,y+1)) return true;
	if (isValid(x,y-1) && dfs(x,y-1)) return true;
	return false;
}

int main(){
	while (cin >> n >> m) {
		int x,y;
		v = vector<vector<int>>(n, vector<int>(m, 0));
		v2 = vector<string>(n);
		for (int i = 0; i < n; ++i) {
			cin >> v2[i];
			for (int j = 0; j < m; ++j) {
				if (v2[i][j] == 'X') v[i][j] = -1;
				else if (v2[i][j] == 'P') {x = i; y = j;}
				else if (v2[i][j] == 'F') {
					for (int i2 = i-1; i2 <= i+1; ++i2)
						for (int j2 = j-1; j2 <= j+1; ++j2) {
							if (isValid(i2, j2)) v[i2][j2] = -1;
						}
				}
			}
		}
		cout << (dfs(x,y) ? "si" : "no") << endl;
	}	
}