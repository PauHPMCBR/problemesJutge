#include <bits/stdc++.h>
using namespace std;
 #define int long long
vector<vector<int>>v;

int dfs(int x) {
	if (v[x].size() == 0) return 1;
	if (v[x].size() == 1) return dfs(v[x][0])+1;
	return min(dfs(v[x][0]), dfs(v[x][1]))*2+1;
}

signed main(){
	int t,n;
	cin >> t;
	while (t--) {
		cin >> n;
		v = vector<vector<int>>(n);
		for (int i = 0; i < n-1; i++) {
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		cout << dfs(0) << endl;
	}
	
}
