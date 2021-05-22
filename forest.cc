#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>visited;

bool dfs(int x, int par) {
	if (visited[x]) return true;
	visited[x] = 1;
	for (auto i : v[x]) {
		if (i != par) {
			if (visited[i] == 1) return false;
			if (!dfs(i, x)) return false;
		}
	}
	visited[x] = 2;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (m >= n) {
		cout << "NO" << endl;
		return 0;
	}
	v = vector<vector<int>>(n);
	visited = vector<int>(n, 0);
	for (int i = 0; i < m; ++i) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	bool tree = true;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) if (!dfs(i, -1)) {
			tree = false;
			break;
		}
	}
	if (tree) cout << "YES" << endl;
	else cout << "NO" << endl;
}