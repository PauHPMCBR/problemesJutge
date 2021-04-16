#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>tin;
vector<int>fup;
set<int>sol;

int timer = 1;
void dfs(int x, int par) {
	int mobe = 0;
	tin[x] = timer;
	++timer;
	fup[x] = tin[x];
	for (auto i : v[x]) {
		if (tin[i] == 0) {
			dfs(i, x);
			++mobe;
			fup[x] = min(fup[x], fup[i]);
			if (par != -1 && fup[i] >= tin[x]) sol.insert(x+1);
		}
		else if (i != par) {
			fup[x] = min(fup[x], tin[i]);
		}
	}
	if (par == -1) {
		if (mobe > 1) sol.insert(x+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	v = vector<vector<int>>(n);
	tin = vector<int>(n, 0);
	fup = vector<int>(n, 0);
	for (int i = 1; i <= m; ++i) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	dfs(0, -1);
	cout << sol.size() << endl;
	for (auto i : sol) cout << i << ' ';
	cout << endl;
}