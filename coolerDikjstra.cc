#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>>g;
vector<ll>w;
vector<bool>v;
vector<ll>dist;
ll n,m;



void dijkstra(ll x){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,x});
    dist[x]=w[x];
    while(!pq.empty()){
        ll actual=pq.top().second;
        pq.pop();
        if(v[actual]) continue;
        v[actual]=true;
        //cout << "actual" << actual << endl;
        for(auto node:g[actual]){
        	//cout << adj.second << endl;
            dist[node] = min(dist[node], dist[actual]+w[node]);
            pq.push({dist[node], node});
        }
    }
}

 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    g=vector<vector<ll>>(n);
    w = vector<ll>(n);
    v=vector<bool>(n);
    dist = vector<ll>(n, LLONG_MAX);
    for (ll i = 0; i < n; ++i) cin >> w[i];
    for(ll i=0; i<m; ++i){
        ll a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dijkstra(0);
    for (ll i = 0; i < n; ++i) {
    	cout << dist[i] << ' ';
    }
    cout<< endl;
    
}