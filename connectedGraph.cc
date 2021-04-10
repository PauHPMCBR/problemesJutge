#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
vector<bool>visited;

void dfs(int x) {
	for (auto i : v[x]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		v = vector<vector<int>>(n);
		visited = vector<bool>(n, false);
		for (int i = 0; i < m; ++i) {
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				++c;
				dfs(i);
			}
		}
		cout << c << endl;
	}
}