#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<pair<int,int>>>v;
vector<vector<int>>dist;
vector<bool>visited;

priority_queue<pair<int,int>>pq;
void dikjstra(int ind) {
	while (!pq.empty()) {
		int x = pq.top().second; pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		for (auto i : v[x]) {
			if (dist[i.first][ind] > dist[x][ind] + i.second and not visited[i.first]) {
				dist[i.first][ind] = dist[x][ind] + i.second;
				pq.push({-dist[i.first][ind], i.first});
			}
		}
	}
}

vector<vector<int>> cass(const vector<vector<int>>& v1) {
	vector<vector<int>>v2;
	int os = 0;
	v2.push_back({v1[0][1], v1[0][2], v1[0][0], v1[0][3]});
	for (int i = 1; i < v1.size(); ++i) {
		++os;
		if (v1[i][0] >= v1[i-os][0] and v1[i][1] >= v1[i-os][1] and v1[i][2] >= v1[i-os][2])
			continue;
		os = 0;
		v2.push_back({v1[i][1], v1[i][2], v1[i][0], v1[i][3]});
	}
	return v2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> e;
	v = vector<vector<pair<int,int>>>(n);
	for (int i = 0; i < e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}

	dist = vector<vector<int>>(n, vector<int>(4, 1e9));
	dist[0][0] = 0;
	dist[1][1] = 0;
	dist[2][2] = 0;
	for (int i = 0; i < n; ++i) dist[i][3] = i;

	for (int i = 0; i < 3; ++i) {
		while (!pq.empty()) pq.pop();
		visited = vector<bool>(n, 0);
		pq.push({0,i});
		dikjstra(i);
	}

		
	for (int i = 0; i < 3; ++i) {
		sort(dist.begin(), dist.end());
		for (auto i : dist) {
			cout << i[3] << i[0] << i[1] << i[2] << endl;
		}cout << endl;
		dist = cass(dist);
	}
	cout << dist.size() << endl;
}