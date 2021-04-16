#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>v;
vector<int>visited;
vector<int>parent;
vector<int>cycle;

void dfs(int x) {
	visited[x] = 1;
	for (auto i : v[x]) {
		if (!visited[i]) {
			parent[i] = x;
			dfs(i);
		}
		else if (visited[i] == 1 && cycle.size() == 0) {
			int current = x;
			while (current != i) {
				cycle.push_back(current);
				current = parent[current];
			}
			cycle.push_back(i);
		}
	}
	visited[x] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		v = vector<vector<int>>(n);
		parent = vector<int>(n, 0);
		visited = vector<int>(n, 0);
		cycle.clear();
		int a,b;
		while (m--) {
			cin >> a >> b;
			v[a-1].push_back(b-1);
		}
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		if (cycle.size() == 0) cout << "YES" << "\n";
		else {
			cout << "NO" << "\n" << cycle.size() << "\n";
			for (int i = cycle.size()-1; i >= 0; --i) cout << cycle[i]+1 << ' ';
			cout << cycle[cycle.size()-1]+1 << "\n";
		}
	}
}