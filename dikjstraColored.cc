#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	vector<vector<vector<ll>>>v(n);
	while (m--) {
		ll a,b,c,w;
		cin >> a >> b >> c >> w;
		v[a-1].push_back({b-1,c-1,w});
		v[b-1].push_back({a-1,c-1,w});
	}
	priority_queue<vector<ll>>q;
	vector<vector<bool>>visited(n, vector<bool>(3,false));
	vector<vector<pair<ll,ll>>>parent(n, vector<pair<ll,ll>>(3));
	vector<vector<ll>>dist(n, vector<ll>(3, 1e15));
	q.push({0,0,-1});
	bool gotSol = false;
	parent[0][0] = {-1, -1};
	dist[0][0] = 0;
	dist[0][1] = 0;
	dist[0][2] = 0;
	while(!q.empty() && !gotSol) {
		ll weight = -q.top()[0];
		ll node = q.top()[1];
		ll colour = q.top()[2];
		q.pop();
		if (visited[node][abs(colour)]) continue;
		visited[node][abs(colour)] = true;
		
		if (node == n-1) {
			gotSol = true;
			cout << "YES" << endl;
			vector<ll>sol;
			ll curr = node;
			ll currCol = colour;
			while (curr != -1) {
				sol.push_back(curr);
				ll lel = curr;
				curr = parent[curr][currCol].first;
				currCol = parent[lel][currCol].second;
			}
			cout << sol.size()-1 << endl;
			for (ll j = sol.size()-2; j >= 0; --j) cout << sol[j]+1 << ' ';
			cout << endl;
			return 0;
		}


		for (auto i : v[node]) {
			//
			if (i[1] != colour && dist[i[0]][i[1]] > weight+i[2]) {
				parent[i[0]][i[1]] = {node, abs(colour)};
				dist[i[0]][i[1]] = weight+i[2];
				q.push({-(i[2]+weight), i[0], i[1]});
				//
				
			}
		}
	}
	if (!gotSol) {
		cout << "NO" << endl;
	}
}