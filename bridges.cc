#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>v;
vector<int>tin;
vector<int>fup;
vector<int>sol;

int timer = 1;
void dfs(int x, int par) {
	tin[x] = timer;
	++timer;
	fup[x] = tin[x];
	for (auto [i, id] : v[x]) {
		if (tin[i] == 0) {
			dfs(i, x);
			fup[x] = min(fup[x], fup[i]);
			if (fup[i] > tin[x]) sol.push_back(id);
		}
		else if (i != par) {
			fup[x] = min(fup[x], tin[i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	v = vector<vector<pair<int,int>>>(n);
	tin = vector<int>(n, 0);
	fup = vector<int>(n, 0);
	for (int i = 1; i <= m; ++i) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back({b-1, i});
		v[b-1].push_back({a-1, i});
	}
	dfs(0, -1);
	sort(sol.begin(), sol.end());
	cout << sol.size() << endl;
	for (auto i : sol) cout << i << ' ';
	cout << endl;
}