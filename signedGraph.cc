#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,bool>>>v;
vector<int>visited;
vector<pair<int,bool>>parent;
bool lel = true;
 
void dfs(int x) {
	cout << x << endl;
	visited[x] = 1;
	for (auto i : v[x]) {
		if (!visited[i.first]) {
			parent[i.first] = {x,i.second};
			dfs(i.first);
		}
		else if (visited[i.first] == 1 && parent[x].first != i.first) {
			int current = x;
			bool positive = parent[i.first].second;
			while (current != i.first) {
				cout << ' ' << x << ' ' << current << ' ' << i.first << endl;
				if (parent[current].second) positive = !positive;
				current = parent[current].first;
			}
			if (!positive) {
				lel = false;
				return;
			}
		}
	}
	visited[x] = 2;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n >> m) {
		v = vector<vector<pair<int,bool>>>(n);
		parent = vector<pair<int,bool>>(n, {0,0});
		visited = vector<int>(n, 0);
		int a,b,c;
		while (m--) {
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b, (c==-1)));
			v[b].push_back(make_pair(a, (c==-1)));
		}
		for (int i = 0; i < n && lel; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << (lel ? "yes" : "no") << endl;
	}
}