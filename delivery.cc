#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<pair<ll,ll>>>v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    v = vector<vector<pair<ll,ll>>>(n);
    while (m--) {
        ll a,b,c;
        cin >> a >> b >> c;
        v[a-1].push_back({b-1,c});
        v[b-1].push_back({a-1,c});
    }
    
    priority_queue<pair<ll,ll>>pq;
    vector<ll>dist1(n, 1e15);
    vector<bool>visited(n, false);
    dist1[0] = 0;
    pq.push({0,0});
    while (!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i : v[node]) {
            ll u = i.first;
            ll d = i.second;
            if (dist1[node]+d < dist1[u]) {
                dist1[u] = dist1[node]+d;
                pq.push({-dist1[u],u});
            }
        }
    }
    pq = priority_queue<pair<ll,ll>>();
    vector<ll>dist2(n, 1e15);
    visited = vector<bool>(n, false);
    dist2[1] = 0;
    pq.push({0,1});
    while (!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i : v[node]) {
            ll u = i.first;
            ll d = i.second;
            if (dist2[node]+d < dist2[u]) {
                dist2[u] = dist2[node]+d;
                pq.push({-dist2[u],u});
            }
        }
    }
    vector<pair<ll,ll>>dif;
    for(ll i = 2; i < n; ++i) {
        dif.push_back({dist1[i]-dist2[i], i});
    }
    sort(dif.begin(),dif.end());
    ll ans = 0;
    for(ll i = 0; i < (n-2)/2; ++i) {
        ans += dist1[dif[i].second];
    }
    for(ll i = (n-2)/2; i < n-2; ++i) {
        ans += dist2[dif[i].second];
    }
    cout << ans*2 << endl;
} 