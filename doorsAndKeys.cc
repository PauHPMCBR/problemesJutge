#include <bits/stdc++.h>
using namespace std;

vector<int>v;
vector<int>numKeys;
vector<bool>visited;
int dfs(int x) {
	visited[x] = true;
	if (numKeys[x] != -1) return numKeys[x];
	if (visited[v[x]]) return 1;
	return numKeys[x] = dfs(v[x])+1;
}

int main(){
	int n;
	cin >> n;
	int maxim = 1;
	v = vector<int>(n);
	visited = vector<bool>(n, false);
	numKeys = vector<int>(n, -1);
	for (int i = 0; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		v[a-1] = b-1;
	}
	for (int i = 0; i < n; ++i) {
		if (dfs(i) > maxim) maxim = dfs(i);
	}
	cout << maxim << endl;
}