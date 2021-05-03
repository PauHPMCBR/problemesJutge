#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n, s, f;
	cin >> n >> s >> f;
	--s; --f;
	vector<vector<int>>v(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool b;
			cin >> b;
			if (b) v[i].push_back(j);
		}
	}
	int shortestPath = 0;
	queue<pair<int,int>>q;
	q.push({s,0});
	vector<bool>visited(n, false);
	visited[s] = true;
	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (node == f) {
			shortestPath = dist;
			break;
		}
		for (auto i : v[node]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push({i,dist+1});
			}
		}
	}
	cout << shortestPath << endl;
}