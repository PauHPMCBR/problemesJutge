#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <vector <char>>v;

bool isValid(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return v[x][y] == '.';
}

void dfs(int x, int y) {
	v[x][y] = '#';
	if (isValid(x+1, y)) dfs(x+1, y);
	if (isValid(x-1, y)) dfs(x-1, y);
	if (isValid(x, y+1)) dfs(x, y+1);
	if (isValid(x, y-1)) dfs(x, y-1);
}

int main(){
	cin >> n >> m;
	int rooms = 0;
	v = vector<vector<char>>(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '.') {
				++rooms;
				dfs(i, j);
			}
		}	

	cout << rooms << endl;
}