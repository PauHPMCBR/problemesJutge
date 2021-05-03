#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<vector<int>>trans;
vector<int>cost;

vector<int>tout;
vector<bool>visited;
int counter = 1;
void dfs(int x) {
	for (auto i : v[x]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
	tout.push_back(x);
}

int minCost;
void dfs2(int x) {
	if (cost[x] < minCost) minCost = cost[x];
	for (auto i : trans[x]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs2(i);
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	cost = vector<int>(n);
	for (int i = 0; i < n; ++i) cin >> cost[i];
	v = vector<vector<int>>(n);
	trans = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		trans[b-1].push_back(a-1);
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) dfs(i);
	}
	int totalCost = 0;
	visited = vector<bool>(n, false);
	reverse(tout.begin(), tout.end());
	for(auto i : tout) {
		if (visited[i]) continue;
		minCost = 1e6;
		visited[i] = true;
		dfs2(i);
		totalCost += minCost;
	}
	cout << totalCost << endl;
}