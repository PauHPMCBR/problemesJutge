#include <bits/stdc++.h>
using namespace std;
int n,m;

bool isValid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<bool>>v(n, vector<bool>(m, true));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char prov;
			cin >> prov;
			if (prov == '#') v[i][j] = false;
		}
	}
	int k; cin >> k;
	set<pair<int,int>>sol;
	queue<vector<int>>q;
	int a,b;
	while (k--) {
		cin >> a >> b;
		q.push({a-1,b-1,0});
		v[a-1][b-1] = false;
	}
	int currentIt = 0;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int it = q.front()[2];
		q.pop();
		if (it != currentIt) {
			sol.clear();
			currentIt = it;
		}
		sol.insert({x,y});
		if (isValid(x+1, y) && v[x+1][y]) {q.push({x+1,y,it+1}); v[x+1][y] = false;}
		if (isValid(x-1, y) && v[x-1][y]) {q.push({x-1,y,it+1}); v[x-1][y] = false;}
		if (isValid(x, y+1) && v[x][y+1]) {q.push({x,y+1,it+1}); v[x][y+1] = false;}
		if (isValid(x, y-1) && v[x][y-1]) {q.push({x,y-1,it+1}); v[x][y-1] = false;}
		if (isValid(x+1, y+1) && v[x+1][y+1]) {q.push({x+1,y+1,it+1}); v[x+1][y+1] = false;}
		if (isValid(x-1, y-1) && v[x-1][y-1]) {q.push({x-1,y-1,it+1}); v[x-1][y-1] = false;}
		if (isValid(x-1, y+1) && v[x-1][y+1]) {q.push({x-1,y+1,it+1}); v[x-1][y+1] = false;}
		if (isValid(x+1, y-1) && v[x+1][y-1]) {q.push({x+1,y-1,it+1}); v[x+1][y-1] = false;}
	}
	cout << sol.size() << endl;
	for (auto i : sol) cout << i.first+1 << ' ' << i.second+1 << endl;
}