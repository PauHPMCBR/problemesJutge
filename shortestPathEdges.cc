#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	vector<vector<int>>v(n);

	while (m--) {
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	queue<vector<int>>q;
	q.push({a});
	vector<int>visited(n, false);
	visited[a] = true;
	while (!q.empty()) {
		vector<int>v = q.front();
		int node = v[v.size()-1];
		q.pop();
		if (node == b) {
			for (auto i : v) cout << i.second+1 << endl;
			break;
		}
		for (int i = 0; i < 8; ++i) {
			if (isValid(n+x[i], m+y[i])) if (!visited[n+x[i]][m+y[i]]) {
				v.push_back({n+x[i], m+y[i]});
				visited[n+x[i]][m+y[i]] = true;
				q.push(v);
				v.pop_back();
			}
		}
	}
}