#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>v;
vector<int>tin;
vector<int>tout;

int timeIn = 0;
int timeOut = 0;
void dfs(int x) {
	tin[x] = timeIn;
	++timeIn;
	for (auto i : v[x]) {
		dfs(i);
	}
	tout[x] = timeOut;
	++timeOut;
}

bool isAncestor(int x, int y) {
	return (tin[x] < tin[y] && tout[x] > tout[y]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v = vector<vector<int>>(n);
	tin = vector<int>(n);
	tout = vector<int>(n);
	int prov;
	for (int i = 1; i < n; ++i) {
		cin >> prov;
		v[prov-1].push_back(i);
	}
	dfs(0);
	int q;
	cin >> q;
	while (q--) {
		int a,b;
		cin >> a >> b;
		--a; --b;
		if (isAncestor(b,a)) cout << 2 << endl;
		else if (isAncestor(a,b)) cout << 1 << endl;
		else cout << 3 << endl;
	}
}