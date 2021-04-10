#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>v;
vector<int>visited;
vector<int>ans;

bool dfs(int x, int pre) {
	for (auto i : v[x]) {
		if (visited[i] == 1) {
			if (i != pre) {
				ans.push_back(x);
				return true;
			}
		}
		else if (!visited[i]) {
			visited[i] = 1;
			if (dfs(i, x)) {
				ans.push_back(x);
				return true;
			}
			visited[i] = 2;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		v = vector<vector<int>>(n);
		visited = vector<int>(n, 0);
		ans.clear();
		int a,b;
		while (m--) {
			cin >> a >> b;
			v[a-1].push_back(b-1);
		}
		bool gotSol = false;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				if (dfs(i, i)) {
					cout << "NO" << "\n";
					cout << ans.size()-1 << "\n";
					for (int i = ans.size()-1; i >= 0; --i) cout << ans[i]+1 << ' ';
					cout << "\n";
					gotSol = true;
					break;
				}
			}
		}
		if (!gotSol) cout << "YES" << "\n";
	}
}