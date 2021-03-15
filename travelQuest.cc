#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>v(n+1);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j < b; ++j) v[j].push_back({-c,b});
	}
	vector<int>dist(n+1, -1e9);
	vector<bool>visited(n+1, false);
	priority_queue<pair<int,int>>pq;
	pq.push({0,1});
	dist[1] = -1;
	int res = -1;
	while (!pq.empty()) {
		int a = pq.top().second;
		if (a == n) {
			res = pq.top().first;
			break;
		}
		pq.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto i : v[a]) {
			int node = i.second;
			int pes = i.first;
			if (min(dist[a],pes) > dist[node]) {
				dist[node] = min(dist[a], pes);
				pq.push({dist[node], node});
			}
		}
	}
	cout << -res << endl;
}