#include <bits/stdc++.h>
using namespace std;

	int n;
vector<vector<int>>dist;
vector<bool>visited;
bool dfs(int x) {
	visited[x] = true;
	if (x == 1) return true;
	for (int i = 0; i < n+2; ++i) {
		if (!visited[i] && dist[x][i] < 1000000) {
			if (dfs(i)) return true;
		}
	}
	return false;
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cin >> n;
	vector<vector<int>>mobe;
	mobe.push_back({0,0,0});
	mobe.push_back({a,b,c});
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >>c;
		mobe.push_back({a,b,c});
	}
	dist = vector<vector<int>>(n+2, vector<int>(n+2));
	visited = vector<bool>(n+2, false);
	for (int i = 0; i <= n+1; ++i) {
		for (int j = i; j <= n+1; ++j) {
			dist[i][j] = (mobe[i][0]-mobe[j][0])*(mobe[i][0]-mobe[j][0]) + (mobe[i][1]-mobe[j][1])*(mobe[i][1]-mobe[j][1]) + (mobe[i][2]-mobe[j][2])*(mobe[i][2]-mobe[j][2]);
			dist[j][i] = dist[i][j];
		}
	}
	if (dfs(0)) cout << "yes" << endl;
	else cout << "no" << endl;
}