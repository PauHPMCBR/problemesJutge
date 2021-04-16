#include <bits/stdc++.h>
using namespace std;
vector<int>parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void join(int x, int y) {
	int parentx = find(x);
	int parenty = find(y);
	if (parenty != parentx) {
		parent[parenty] = parentx;
	}
}


int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>>v;
	parent = vector<int>(n);
	for (int i = 0; i < n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		int a,b;
		cin >> a >> b;
		v.push_back({a-1,b-1});
	}
	vector<int>sol;
	sol.push_back(n);
	for (int i = m-1; i >= 0; --i) {
		int x = v[i].first;
		int y = v[i].second;
		if (find(x) != find(y)) --n;
		join(x,y);
		sol.push_back(n);
	}
	for (int i = sol.size()-2; i >= 0; --i) cout << sol[i] << ' ';
	cout << endl;
}