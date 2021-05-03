#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>v(n);
	++m;
	while (--m) {
		int a,b,c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1,c-1});
		v[b-1].push_back({a-1,c-1});
	}
	queue<pair<int,int>>q;
	vector<vector<bool>>visited(n, vector<bool>(3,false));
	vector<vector<pair<int,int>>>parent(n, vector<pair<int,int>>(3));
	visited[0][0] = true;
	visited[0][1] = true;
	visited[0][2] = true;
	q.push({0,-1});
	bool gotSol = false;
	parent[0][0] = {-1, -1};
	while(!q.empty() && !gotSol) {
		int node = q.front().first;
		int colour = q.front().second;
		q.pop();
		for (auto i : v[node]) {
			if (i.second != colour && !visited[i.first][i.second]) {
				visited[i.first][i.second] = true;
				parent[i.first][i.second] = {node, abs(colour)};
				q.push({i.first, i.second});

				if (i.first == n-1) {
					gotSol = true;
					cout << "YES" << endl;
					vector<int>sol;
					int curr = i.first;
					int currCol = i.second;
					while (curr != -1) {
						sol.push_back(curr);
						int lel = curr;
						curr = parent[curr][currCol].first;
						currCol = parent[lel][currCol].second;
					}
					cout << sol.size()-1 << endl;
					for (int j = sol.size()-2; j >= 0; --j) cout << sol[j]+1 << ' ';
					cout << endl;
				}
			}
		}
	}
	if (!gotSol) {
		cout << "NO" << endl;
	}
}