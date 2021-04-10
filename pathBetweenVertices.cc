#include <iostream>
#include <vector>
using namespace std;
int n, a, b;
vector<vector<int>>v;
vector<int>ans;
vector<bool>visited;

bool dfs(int x) {
	if (x == b-1) {
		ans.push_back(b-1);
		return true;
	}
	for (auto i : v[x]) {
		if (!visited[i]) {
			visited[i] = true;
			if (dfs(i)) {
				ans.push_back(x);
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b;
	bool prov;
	v = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> prov;
			if (prov) v[i].push_back(j);
		}
	}
	visited[a-1] = true;
	if (dfs(a-1)) {
		cout << ans.size()-1 << endl;
		for (int i = ans.size()-1; i >= 0; --i) cout << ans[i]+1 << ' ';
		cout << endl;
	}
	else cout << -1 << endl;
}