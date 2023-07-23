#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,bool>>>v;
vector<int>visited;
vector<pair<int,bool>>parent;
bool lel = true;

vector<bool>isPositive;

void dfs(int x) {
	visited[x] = 1;
	for (auto i : v[x]) {
		if (!visited[i.first]) {
			parent[i.first] = {x,i.second};
			isPositive[i.first] = isPositive[x] ^ i.second; //if i.second then reverse
			dfs(i.first);
			if (!lel) return;
		}
		else if (visited[i.first] == 1 && parent[x].first != i.first) {
			// int current = x;
			// bool isPositive = !i.second;
			// while (current != i.first) {
			// 	if (parent[current].second) isPositive = !isPositive;
			// 	current = parent[current].first;
			// }

			// if (!isPositive) {
			// 	lel = false;
			// 	return;
			// }

			if (!((isPositive[x] == isPositive[i.first]) ^ i.second)) {
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
	while (cin >> n >> m) {
		v = vector<vector<pair<int,bool>>>(n);
		parent = vector<pair<int,bool>>(n, {0,0});
		visited = vector<int>(n, 0);
		isPositive = vector<bool>(n, 1);
		while (m--) {
			int a,b,c;
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