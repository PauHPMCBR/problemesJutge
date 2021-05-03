#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	vector<vector<int>>v(n);
	while(m--) {
		int x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	vector<int>dist(n, -1);
	dist[a-1] = 0;
	queue<int>q;
	q.push(a-1);
	int distance = -1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : v[node]) {
			if (dist[i] == -1) {
				dist[i] = dist[node]+1;
				q.push(i);
				if (i == b-1) distance = dist[i];
			}
		}
	}

	set<pair<int,int>>sol;
	q = queue<int>();
	q.push(b-1);
	vector<int>dist2(n, -1);
	vector<bool>visited(n, false);
	dist2[b-1] = 0;
	visited[b-1] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : v[node]) {
			if (dist2[i] == -1) dist2[i] = dist2[node]+1;
			if (dist[node]+dist2[i]+1 == distance) sol.insert({min(i,node), max(i,node)});
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << sol.size() << endl;
	for (auto i : sol) cout << i.first+1 << ' ' << i.second+1 << endl;
}