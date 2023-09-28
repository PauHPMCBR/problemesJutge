#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, m;

vector<vector<pair<int,int>>>v;
vector<vector<pair<int,int>>>rev;
vector<pair<int,int>>par;
vector<vector<pair<int,int>>>sons;

pair<int,int>specialEdge;
int specialEdgeCost;

int totalCost;

void noSpecial(int pos) {
	pair<int,int>minEdge = {-1,-1};
	for (auto i : rev[pos]) {
		if (minEdge.second == -1 || i.second < minEdge.second) minEdge = i;
	}
	par[pos] = minEdge;
	sons[minEdge.first].push_back({pos, minEdge.second});
	totalCost += minEdge.second;
}


vector<bool>visited;
void dfs(int x, int forbidden) {
	if (x == forbidden) return;
	visited[x] = true;
	for (auto i : sons[x]) dfs(i.first, forbidden);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		v.clear();
		v.resize(n);
		rev.clear();
		rev.resize(n);
		//par.clear();
		//par.resize(n);
		par = vector<pair<int,int>>(n, {-1,-1});
		sons.clear();
		sons.resize(n);

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b;
			if (a > b) {
				specialEdge = {b,a};
				specialEdgeCost = c;
			}
			else {
				v[a].push_back({b,c});
				rev[b].push_back({a,c});
			}
		}

		totalCost = 0;

		//create graph without backwards
		for (int i = 1; i < n; ++i) noSpecial(i);

		int minTotalCost = totalCost;

		if (specialEdge.first == 0) {
			cout << minTotalCost << endl;
			continue; //can't go back to first node, pointless
		}

		//check if to go to Y, it passes through X:
		bool found = false;
		int x = specialEdge.second;
		while (x != 0) {
			x = par[x].first;
			if (x == specialEdge.first) {
				found = true;
				break;
			}
		}
		if (!found) {
			//compare edge to go to X and special: 
			if (specialEdgeCost < par[specialEdge.first].second)
				minTotalCost = minTotalCost - par[specialEdge.first].second + specialEdgeCost;
		}
		else {

			visited = vector<bool>(n, false);
			dfs(0, specialEdge.first);

			//check all possible replacements:
			int x = specialEdge.second;
			//x = par[x].first;
			int bestSave = 1e18; //will be POSITIVE
			while (x != specialEdge.first) {
				//try to remove parent and put a new one before specialEdge.first:
				int minCostEdge = 1e18;
				for (auto i : rev[x]) {
					if (!visited[i.first]) continue;
					minCostEdge = min(minCostEdge, i.second);
				}
				bestSave = min(bestSave, minCostEdge - par[x].second); //should NEVER be negative

				x = par[x].first;
			}
			minTotalCost = min(minTotalCost, minTotalCost - par[specialEdge.first].second + specialEdgeCost + bestSave); //?
			//aka remove last edge of path 1,x ; add special edge ; change one edge inside the interval (unnecessary cycle), but needs a start
		}

		cout << minTotalCost << endl;
	}
}