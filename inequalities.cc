#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<set<int>>v;
vector<bool>visited;

bool dfs(int x, int missing) {
	visited[x] = true;
	if (missing == 1) {
		cout << "YES" << endl << x << ' ';
		return true;
	}
	for (auto i : v[x]) {
		if (dfs(i, missing-1)) {
			cout << x << ' ';
			return true;
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	v = vector<set<int>>(n);
	visited = vector<bool>(n, false);
	int minim = -1;
	int missing = m;
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a].insert(b);
		if (minim == -1 || minim == b) minim = a;
	}
	dfs(minim, missing);
}