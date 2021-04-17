#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>tin;
vector<int>fup;
vector<pair<int,int>>sol;

int timeIn = 1;
void dfs(int x, int par) {
	tin[x] = timeIn;
	fup[x] = tin[x];
	++timeIn;
	for (auto i : v[x]) {
		if (!tin[i]) {
			dfs(i, x);
			fup[x] = min(fup[x], fup[i]);
			if (fup[i] > tin[x]) sol.push_back({x,i});
		}
		else if (i != par) fup[x] = min(fup[x], tin[i]);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	v = vector<vector<int>>(n);
	fup = vector<int>(n,0);
	tin = vector<int>(n,0);
	for (int i = 0; i < m; ++i) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	dfs(0, -1);
	for (auto i : sol) cout << i.first << ' ' << i.second << endl;
}