#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a,b,c;
	cin >> n >> m >> a >> b >> c;
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
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : v[node]) {
			if (dist[i] == -1) {
				dist[i] = dist[node]+1;
				q.push(i);
			}
		}
	}

	vector<int>dist3(n, -1);
	dist3[c-1] = 0;
	q = queue<int>();
	q.push(c-1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : v[node]) {
			if (dist3[i] == -1) {
				dist3[i] = dist3[node]+1;
				q.push(i);
			}
		}
	}

	int sol = 1e9;
	q = queue<int>();
	q.push(b-1);
	vector<int>dist2(n, -1);
	dist2[b-1] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (dist[node]+dist2[node]+dist3[node] < sol) sol = dist[node]+dist2[node]+dist3[node];
		for (auto i : v[node]) {
			if (dist2[i] == -1) {
				dist2[i] = dist2[node]+1;
				q.push(i);
			}
		}
	}
	cout << sol << endl;
}