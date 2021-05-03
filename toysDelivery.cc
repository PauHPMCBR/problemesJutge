#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<vector<ll>>>v;

bool bfs(ll w){
    priority_queue<pair<ll,ll>>pq;
    vector<bool>visited(n, false);
    vector<ll>dist(n, 1e15);
    dist[0] = 0;
    pq.push({0,0});
    while (!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i : v[node]) {
            ll u = i[0];
            ll d = i[1];
            ll cap = i[2];
            if (dist[node]+d < dist[u] and w<=cap) {
                dist[u] = dist[node]+d;
                pq.push({-dist[u],u});
            }
        }
    }
    return (dist[n-1] <= 525600);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    v = vector<vector<vector<ll>>>(n);
    while (m--) {
        ll a,b,t,w;
        cin >> a >> b >> t >> w;
        v[a-1].push_back({b-1,t,w});
        v[b-1].push_back({a-1,t,w});
    }
    ll left = 1;
    ll right = 1e9;
    while(left <= right){
        ll mid = (left+right)/2;
        if(!bfs(mid)) right = mid-1;
        else left = mid+1;
    }
    cout << left-1 << endl;
} 