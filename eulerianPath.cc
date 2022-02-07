#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool>used;
vector<int>path;
vector<vector<pair<int,int>>>v;

void dfs(int x) {
	path.push_back(x);
	for (auto i : v[x]) {
		if (used[i.second]) continue;
		used[i.second] = true;
		dfs(i.first);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<pair<int,int>>>(n);
	used = vector<bool>(m, false);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a-1].push_back({b-1,i});
		v[b-1].push_back({a-1,i});
	}
	dfs(0);
	if (path.size() <= m) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (auto i : path) cout << i+1 << ' ';
		cout << endl;
	}
}