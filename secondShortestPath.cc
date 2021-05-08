#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<pair<ll,ll>>>v;
vector<vector<pair<ll,ll>>>v2;
vector<ll>d;
vector<ll>d2;

void dijkstra1(ll x){
	d[x]=0;
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,x});
	while (!pq.empty()){
		ll node=pq.top().second;
		ll pes=-pq.top().first;
		pq.pop();
		if (pes > d[node]) continue;
		for (auto i : v[node]){
			if (i.second+pes < d[i.first]){
				d[i.first] = i.second + pes;
				pq.push({-d[i.first], i.first});
			}
		}
	}
}

void dijkstra2(ll x) {
	d2[x] = 0;
	priority_queue<pair<ll,ll>>pq;
	pq.push({0,x});
	while (!pq.empty()){
		ll node=pq.top().second;
		ll pes=-pq.top().first;
		pq.pop();
		if (pes > d2[node]) continue;
		for (auto adj : v2[node]){
			if (adj.second + pes < d2[adj.first]){
				d2[adj.first] = adj.second + pes;
				pq.push({-d2[adj.first], adj.first});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	v = vector<vector<pair<ll,ll>>>(n);
	v2= vector<vector<pair<ll,ll>>>(n);
	d = vector<ll>(n, 1e17);
	while (m--) {
		ll a,b,w;
		cin >> a >> b >> w;
		v[a-1].push_back({b-1, w});
		v2[b-1].push_back({a-1, w});
	}
	dijkstra1(0);
	d2 = vector<ll>(n, 1e17);
	dijkstra2(n-1);
	ll sol = 1e17;
	for (ll i = 0; i < n; ++i) {
		for (auto adj:v[i]){
			if (d[i] != 1e17 && d2[adj.first] != 1e17){
				ll yeet= d[i]+adj.second + d2[adj.first];
				if (yeet > d[n-1] && abs(yeet-d[n-1]) < abs(sol-d[n-1])) {
					sol=yeet;
				}
			}		
		}
	}

	if (sol == 1e17) cout << -1 << endl;
	else cout << sol << endl;

}