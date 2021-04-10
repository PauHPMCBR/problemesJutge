#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
vector<int>visited;
vector<set<int>>components;
int it = -1;

void dfs(int x) {
	for (auto i : v[x]) {
		if (visited[i] != -1) continue;
		visited[i] = it;
		components[it].insert(i);
		dfs(i);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v = vector<vector<int>>(n);
	visited = vector<int>(n, -1);
	while (m--) {
		int x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i] != -1) continue;
		++it;
		visited[i] = it;
		components.push_back({i});
		dfs(i);
	}
	for (int i = 0; i < n; ++i) {
		cout << components[visited[i]].size() << ' ';
	}
	cout << endl;
}