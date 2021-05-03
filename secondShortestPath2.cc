#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<vector<pair<ll,ll>>>v;
vector<ll>parent;
vector<unordered_set<ll>>visited;
set<ll> ans;
void dikjstra() {
	priority_queue<vector<ll>>pq;
    pq.push({0,0,-1});
    while(!pq.empty()){
        ll actual = pq.top()[1];
        ll dist = -pq.top()[0];
        ll parent = pq.top()[2];
        pq.pop();
        if(visited[actual].count(dist)) continue;
        visited[actual].insert(dist);
        if (actual == n-1) {
        	ans.insert(dist);
        	if (ans.size() > 1) return;
        	continue;
        }
        for(auto adj:v[actual]){
        	ll node = adj.first;
        	ll pes = adj.second;
        	if (node == parent) continue;
           	pq.push({-(dist+pes), node, actual});
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<pair<ll,ll>>>(n);
	visited = vector<unordered_set<ll>>(n);
	while (m--) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1,c});
		v[b-1].push_back({a-1,c});
	}
	dikjstra();
	int lel = 0;
	for (auto i : ans) {
		if (lel) cout << i << endl;
		++lel;
		if (lel > 1) return 0;
	}
	cout << -1 << endl;
}