#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<vector<pair<ll,ll>>>v;
vector<ll>parent;
vector<bool>visited;
vector<ll>dist;
ll ans;
void dikjstra(ll ex1, ll ex2) {
	priority_queue<pair<ll,ll>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        ll actual=pq.top().second;
        pq.pop();
        if(visited[actual]) continue;
        visited[actual]=true;
        if (actual == n-1) {ans = dist[actual]; return;}
        for(auto adj:v[actual]){
        	ll node = adj.first;
        	ll pes = adj.second;
        	if ((ex1 == node && ex2 == actual) || (ex2 == node && ex1 == actual)) continue;
        	if (dist[node] > dist[actual]+pes) {
        		dist[node] = dist[actual]+pes;
            	pq.push({-dist[node], node});
            	if (ex1 == -1) parent[node] = actual;
        	}
            
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<pair<ll,ll>>>(n);
	visited = vector<bool>(n, false);
	parent = vector<ll>(n, -1);
	dist = vector<ll>(n, 1e15);
	while (m--) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1,c});
		v[b-1].push_back({a-1,c});
	}
	dikjstra(-1, -1);
	ll shortestPath = ans;
	ll node = n-1;
	ll sol = -1;
	while (parent[node] != -1) {
		ans = -1;
		visited = vector<bool>(n, false);
		dist = vector<ll>(n, 1e15);
		dikjstra(node, parent[node]);
		if (ans != -1 && ans != shortestPath) {
			if (sol == -1) sol = ans;
			else sol = min(sol, ans);
		}
		node = parent[node];
	}
	cout << sol << endl;
}