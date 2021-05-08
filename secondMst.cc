#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<pair<ll,pair<ll,ll>>>v;
vector<ll>parent;
vector<bool>visited;

ll getParent(ll x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void join(ll x, ll y) {
    x=getParent(x);
    y=getParent(y);
    if(x != y) parent[x]=y;
}

ll kruskal(ll pos) {
    ll sol = 0;
    ll edges = 0;
    parent = vector<ll>(n, 0);
    for (ll i = 0; i < n; ++i) parent[i] = i;
    for (ll i = 0; i < m; ++i) {
        auto actual = v[i].second;
        if (getParent(actual.first) != getParent(actual.second) && i != pos) {
            sol += v[i].first;
            ++edges;
            join(actual.first, actual.second);
        }
    }
    if (edges == n-1) return sol;
    return -1e17;
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll x,y,w;
        cin >> x >> y >> w;
        v.push_back({w, {x-1, y-1}});
    }
    sort(v.begin(), v.end());
    visited=vector<bool>(m);
    ll sol = 0;
    parent = vector<ll>(n, 0);
    for (ll i = 0; i < n; ++i) parent[i] = i;
    for (ll i = 0; i < m; ++i) {
        auto actual = v[i].second;
        if (getParent(actual.first) != getParent(actual.second)){
            sol += v[i].first;
            visited[i] = true;
            join(actual.first, actual.second);
        }
    }
    ll ans = sol;
    ll diff = 1e17;
    for (ll i = 0; i < m; ++i) {
        if (visited[i]) {
            ll prov = kruskal(i);
            if(prov >= sol && abs(prov-sol) <= diff) {
                ans = prov;
                diff = abs(prov-sol);
            }
        }
        
    }
    cout << ans << endl;
} 