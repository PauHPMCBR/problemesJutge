#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>g;
vector<ll>tin;
vector<ll>fup;
ll timer=0;
set<pair<ll,ll>>lel;
vector<bool>v;
vector<set<ll>>g2;

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
map<int,int>id;
int counter = -1;
void dfs2(ll x) {
	id[x] = counter;
    ++ans;
    v[x] = true;
    for (ll adj : g[x]){
    	if (lel.count({x,adj}) || lel.count({adj,x})) {
        	if (id.count(adj)) {
        		g2[id[x]].insert(id[adj]);
        		g2[id[adj]].insert(id[x]);
        	}
        }
        else if (!v[adj]) {
        	dfs2(adj);
        }
        
    }
}

vector<bool>v2;
int edge = -1;
int mostDepth = 0;
void dfs3(ll x, ll depth) {
	if (depth > mostDepth) {
		mostDepth = depth;
		edge = x;
	}
	v2[x] = true;
	for (auto i : g2[x]) {
		if (!v2[i]) dfs3(i, depth+1);
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
    g2 = vector<set<ll>>(n);
    for (ll i = 0; i < n; ++i){
        if (!v[i]){
        	++counter;
            dfs2(i);
        }
    }
    v2 = vector<bool>(n, false);
	dfs3(0, 0);
	if (edge == -1) cout << 0 << endl;
	else {
		mostDepth = 0;
		v2 = vector<bool>(n, false);
		dfs3(edge, 0);
		cout << counter - mostDepth << endl;
	}
} 