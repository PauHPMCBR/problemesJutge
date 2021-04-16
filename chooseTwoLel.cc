#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>g;
vector<ll>tin;
vector<ll>fup;
ll timer=0;
map<pair<ll,ll>,bool>lel;

void dfs(ll x, ll parent){
    ++timer;
    tin[x]=fup[x]=timer;
    for(ll adj:g[x]){
        if(!tin[adj]){
            dfs(adj,x);
            if(fup[adj]>tin[x]) lel[{x,adj}]=true;
            fup[x]=min(fup[x],fup[adj]);
        }else if(adj!=parent) fup[x]=min(fup[x],tin[adj]);
    }
}

vector<bool>v;

ll dfs2(ll x){
    ll ans=0;
    v[x]=true;
    for(ll adj:g[x]){
        if(not v[adj] and not lel[{x,adj}]){
            ans+=(1+dfs2(adj));
        }
    }
    return ans;
}


int main(){
    ll n,m;
    cin>>n>>m;
    g=vector<vector<ll>>(n);
    tin=vector<ll>(n);
    fup=vector<ll>(n);
    v=vector<bool>(n);
    while(m--){
        ll a,b; cin>>a>>b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1);
    ll solu=0;
    ll suma=0;
    vector<ll>comp;
    for(ll i=0; i<n; ++i){
        if(!v[i]){
            ll ok=dfs2(i)+1;
            suma+=ok;
            comp.push_back(ok);
        }
    }

    for(ll i=0; i<comp.size(); ++i){
        solu+=comp[i]*(suma-comp[i]);
        //suma-=comp[i];
    }
    cout<<solu/2<<endl;
} 