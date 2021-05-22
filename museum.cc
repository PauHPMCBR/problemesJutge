#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<char>>v;
vector<vector<bool>>visited;

bool isValid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int xp[] = {0,0,1,-1};
int yp[] = {1,-1,0,0};
vector<vector<int>>dp;
vector<int>alreadyMade;

int dfs(int x, int y, int ind) {
	int count = 0;
	for (int i = 0; i < 4; ++i) {
		if (isValid(x+xp[i], y+yp[i])) {
			if (v[x+xp[i]][y+yp[i]] == '.') {
				if (!visited[x+xp[i]][y+yp[i]]) {
					visited[x+xp[i]][y+yp[i]] = true;
					count += dfs(x+xp[i], y+yp[i], ind);
				}
			}
			else ++count;
		}
		
	}
	dp[x][y] = ind;
	return count;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	v = vector<vector<char>>(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	visited = vector<vector<bool>>(n, vector<bool>(m, 0));
	dp = vector<vector<int>>(n, vector<int>(m));
	int i = 0;
	while (k--) {
		int a,b;
		cin >> a >> b;
		if (visited[a-1][b-1]) {
			cout << alreadyMade[dp[a-1][b-1]] << endl;
		}
		else {
			visited[a-1][b-1] = true;
			alreadyMade.push_back(dfs(a-1,b-1, i));
			cout << alreadyMade[i] << endl;
			++i;
		}
	}
}