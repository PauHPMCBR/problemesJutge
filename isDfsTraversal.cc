#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<unordered_set<int>>v;
vector<int>path;
vector<int>visited;

bool possible = true;
int pathPos;
void dfs() {
	int myNode = path[pathPos];
	//cout << pathPos << ' ' << path[pathPos] << ' ' << possible << endl;
	if (pathPos == k-1) {
		for (auto i : v[myNode]) if (!visited[i]) possible = false;
		return;
	}
	while (v[myNode].count(path[pathPos+1])) {
		if (pathPos == k-1) break;
		if (visited[path[pathPos+1]]) {
			possible = false;
			return;
		}
		visited[path[pathPos+1]] = true;
		++pathPos;
		dfs();
	}

	for (auto i : v[myNode]) if (!visited[i]) possible = false;

	return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> m) {
		v = vector<unordered_set<int>>(n);
		for (int i = 0; i < m; ++i) {
			int a,b;
			cin >> a >> b;
			v[a].insert(b);
			v[b].insert(a);
		}
		cin >> k;
		path = vector<int>(k);
		for (int i = 0; i < k; ++i) cin >> path[i];

			if (path[0] != 0) {
				cout << "no" << endl;
				continue;
			}

		visited = vector<int>(n, 0);

		possible = true;
		visited[path[0]] = true;
		pathPos = 0;
		dfs();
		if (pathPos != k-1) possible = false;

		//for (auto i : visited) if (i == 0) possible = false;
		cout << (possible ? "yes" : "no") << endl;

	}
}