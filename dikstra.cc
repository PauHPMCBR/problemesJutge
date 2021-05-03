#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<pair<ll,ll>>>g;
vector<bool>v;
vector<ll>dist;
ll n,m;



void dijkstra(ll x){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,x});
    dist[x]=0;
    while(!pq.empty()){
        ll actual=pq.top().second;
        pq.pop();
        if(v[actual]) continue;
        v[actual]=true;
        //cout << "actual" << actual << endl;
        for(auto adj:g[actual]){
        	//cout << adj.second << endl;
        	ll node = adj.second;
        	ll pes = adj.first;
            dist[node] = min(dist[node], dist[actual]+pes);
            pq.push({dist[node], node});
        }
    }
}

 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    g=vector<vector<pair<ll,ll>>>(n);
    v=vector<bool>(n);
    dist = vector<ll>(n, LLONG_MAX);
    for(ll i=0; i<m; ++i){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a-1].push_back({c, b-1});
        g[b-1].push_back({c, a-1});
    }
    dijkstra(0);
    for (ll i = 0; i < n; ++i) {
    	cout << dist[i] << ' ';
    }
    cout<< endl;
    
}