#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
vector<bool>visited;
int components = 0;

void dfs(int x) {
	for (auto i : v[x]) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	while (m--) {
		int x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i);
		++components;
	}
	cout << components << endl;
}