#include <bits/stdc++.h>
using namespace std;

map<string,double>diff = {{"black",50},{"red",40},{"blue",30},{"green",20}};

set<double>visited;
map<double,<vector<double>>>v;
map<double,double>dist;
void dijkstra(vector<double>x) {
	//x: initial node;  dist: vector from initial to others;  v: node vector;  visited: bool vector
	priority_queue<pair<double,double>, vector<pair<double,double>>, greater<pair<double,double>>>pq;
	pq.push({0,x});
	dist[x] = 0;
	while (!pq.empty()) {
		double a = pq.top().second;
		pq.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto i : v[a]) {
			double node = i.second;
			double pes = i.first;
			dist[node] = min(dist[node], dist[a]+pes);
			pq.push({dist[node], node});
		}
	}
}

int main(){
	double n;
	char mobe, prov;
	double a,b,t;
	double max = 0, min = 1e7;
	while (cin >> mobe) {
		if (mobe == 'L') cin >> t >> a >> b;
		else {
			cin >> prov >> t >> a >> b;
			t = (t/diff[prov])*3600;
			if (a > max) {
				max = a;
			}
			if (b < min) {
				min = b;
			}
		}
		v[a].push_back({t, b});

	}
}