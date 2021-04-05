#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<bool>visited;
int nodesVisited = 0;
void dfs(int x) {
	++nodesVisited;
	for (auto i : v[x]) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	if (m != n-1) {
		cout << "NO" << endl;
		return 0;
	}
	v = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	visited[0] = true;
	dfs(0);
	if (nodesVisited == n) cout << "YES" << endl;
	else cout << "NO" << endl;
}