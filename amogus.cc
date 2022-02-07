#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,bool>>>v;
vector<vector<bool>>visited;
vector<vector<bool>>asigned;

bool possible;
int dfs(int x, bool b, int pos) {
	if (visited[x][pos]) {
		if (asigned[x][pos] == b) return 0;
		else possible = false;
		return 0;
	}
	visited[x][pos] = true;
	asigned[x][pos] = b;
	int res = 0;
	for (auto i : v[x]) {
		res += dfs(i.first, b^i.second, pos);
	}
	return res + (!b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		possible = true;
		cin >> n >> m;
		v = vector<vector<pair<int,bool>>>(n);
		visited = vector<vector<bool>>(n, vector<bool>(2, false));
		asigned = vector<vector<bool>>(n, vector<bool>(2, false));
		vector<bool>noParent(n, true);
		for (int i = 0; i < m; ++i) {
			int a, b;
			string s;
			cin >> a >> b >> s;
			noParent[b-1] = 0;
			v[a-1].push_back({b-1, (s == "imposter")});
		}
		int maxImps = n;
		for (int i = 0; i < n; ++i) {
			if (noParent[i]) {
				int prov = dfs(i, 0, 0);
				maxImps -= min(prov, dfs(i, 1, 1));
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!visited[i][0]) {
				int prov = dfs(i, 0, 0);
				maxImps -= min(prov, dfs(i, 1, 1));
			}
		}
		if (possible) cout << maxImps << endl;
		else cout << -1 << endl;
	}
}