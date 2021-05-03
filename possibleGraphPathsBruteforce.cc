#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
set<vector<int>>sols;

void dfs(int x, vector<int>path, int used) {
	if (used == n-1) {
		path.push_back(x);
		sols.insert(path);
		return;
	}
	for (auto i : v[x]) {
		path.push_back(x);
		dfs(i, path);
		path.pop_back();
	}
}


int main(){
	cin >> n >> m;
	v = vector<vector<int>>(n);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	dfs(0, {}, 1);
	cout << sols.size() << endl;
}