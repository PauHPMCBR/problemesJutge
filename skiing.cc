#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin >> n;
	vector<vector<pair<double,int>>>v(1e6);
	int top = -1, bot = 1e9;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'L') {
			double time;
			int s, e;
			cin >> time >> s >> e;
			if (s > top) top = s;
			if (e > top) top = e;
			if (s < bot) bot = s;
			if (e < bot) bot = e;
			v[s].push_back({time, e});
		}
		else {
			string color;
			double dist;
			int s, e;
			cin >> color >> dist >> s >> e;
			if (s > top) top = s;
			if (e > top) top = e;
			if (s < bot) bot = s;
			if (e < bot) bot = e;
			if (color == "green") dist *= 3600/20;
			else if (color == "blue") dist *= 3600/30;
			else if (color == "red") dist *= 3600/40;
			else dist *= 3600/50;
			v[s].push_back({dist, e});
		}
	}
	double sol = 3600*2;
	priority_queue<pair<double,int>>pq;
	pq.push({0, top});
	vector<bool>visited(1e6, false);
	while (!pq.empty()) {
		double dist = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		if (x == bot) {sol = min(sol, -dist); break;}
		for (auto i : v[x]) {
			pq.push({dist-i.first, i.second});
		}
	}
	cout << setprecision(2) << fixed << sol << endl;
}