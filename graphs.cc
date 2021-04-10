#include <bits/stdc++.h>
using namespace std;

vector<bool>visited;
vector<vector<pair<int,int>>>nodes;
void dfs(int x) {
    visited[x] = true;
    for (auto a : nodes[x]) {
        if (!visited[a.first]) dfs(a.first);
    }
}

void bfs(int x) {
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int a = q.top();
		q.pop();
		for (auto i : nodes[a]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void dijkstra(int x) {
	//x: initial node;  dist: vector from initial to others;  v: node vector;  visited: bool vector
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	pq.push({0,x});
	dist[x] = 0;
	while (!pq.empty()) {
		int a = pq.top().second;
		pq.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto i : v[a]) {
			int node = i.second;
			int pes = i.first;
			dist[node] = min(dist[node], dist[a]+pes);
			pq.push({dist[node], node});
		}
	}
}

void floyd() {
	for (int k = 0; k < n; k++) { 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] + v[k][j] < v[i][j]) 
					v[i][j] = v[i][k] + v[k][j]; 
			} 
		} 
	} 
}
