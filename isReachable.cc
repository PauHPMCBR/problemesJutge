#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<vector<int>>v;
vector<bool>visited;

bool dfs(int x) {
	if (x == b) return true;
	for (auto i : v[x]) {
		if (visited[i]) continue;
		visited[i] = true;
		if (dfs(i)) return true;
	}
	return false;
}


int main(){
	cin >> n >> m >> a >> b;
	--a;
	--b;
	v = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	while (m--) {
		int x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	if (dfs(a)) cout << "YES" << endl;
	else cout << "NO" << endl;
}