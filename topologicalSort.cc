#include <bits/stdc++.h>
using namespace std;
vector<set<int>>v;
vector<int>visited;
stack<int>sol;

bool dfs(int x) {
	visited[x] = 1;
	for (auto i : v[x]) {
		if (!visited[i]) {
			if (!dfs(i)) return false;
		}
		else if (visited[i] == 1) {
			return false;
		}
	}
	visited[x] = 2;
	sol.push(x);
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	v = vector<set<int>>(n);
	visited = vector<int>(n, false);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a].insert(b);
	}
	bool possible = true;
	for (int i = 0; i < n && possible; ++i) {
		if (!visited[i]) {
			if (!dfs(i)) possible = false;
		}
	}
	if (!possible) cout << "NO" << endl;
	else  {
		cout << "YES" << endl;
		vector<int>wtf(n);
		int i = 1;
		while (!sol.empty()) {
			wtf[sol.top()] = i;
			++i;
			sol.pop();
		}
		for (auto i : wtf) cout << i << ' ';
		cout << endl;
	}
}