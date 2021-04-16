#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>g;
vector<ll>tin;
vector<ll>fup;
ll timer=0;
set<pair<ll,ll>>lel;
vector<bool>v;

void dfs(ll x, ll parent){
    ++timer;
    tin[x]=fup[x]=timer;
    for(ll adj : g[x]){
        if(!tin[adj]){
            dfs(adj,x);
            fup[x] = min(fup[x], fup[adj]);
            if (fup[adj] > tin[x]) {
            	lel.insert({x,adj});
            	lel.insert({adj,x});
            }
        }
        else if (adj != parent) fup[x] = min(fup[x], tin[adj]);
    }
}


ll ans = 0;
void dfs2(ll x) {
    ++ans;
    v[x] = true;
    for (ll adj : g[x]){
        if (!v[adj] && !lel.count({x,adj})){
            dfs2(adj);
        }
    }
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    ll n,m;
    cin >> n >> m;
    g = vector<vector<ll>>(n);
    tin = vector<ll>(n, 0);
    fup = vector<ll>(n, 0);
    v = vector<bool>(n, false);
    while (m--){
        ll a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dfs(0, -1);
    
    vector<ll>comp;
    ll suma = 0;
    for (ll i = 0; i < n; ++i){
        if (!v[i]){
        	ans = 0;
            dfs2(i);
            comp.push_back(ans);
            suma += ans;
        }
    }

	ll solu = 0;
    for (ll i = 0; i < comp.size(); ++i) {
    	solu += comp[i]*(suma-comp[i]);
    	suma -= comp[i];
    }
    cout<<solu<<endl;
} 