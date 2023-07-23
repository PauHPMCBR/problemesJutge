#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>x;
vector<vector<int>>v;
int ans;

void dfs(int pos, int parent, int xo) {
	xo ^= x[pos];
	if (pos != 0 and v[pos].size() < 2) ans += xo;
	for (int i : v[pos]) {
		if (i == parent) continue;
		dfs(i, pos, xo);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n){
		ans = 0;
		x = vector<int>(n);
		v = vector<vector<int>>(n);
		for (int i = 0; i < n; ++i) cin >> x[i];
		for (int i = 0; i < n-1; ++i) {
			int a,b;
			cin >> a >> b;
			v[a-1].push_back(b-1);
			v[b-1].push_back(a-1);
		}
		dfs(0, -1, 0);
		cout << ans << endl;
	}
}