#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>g;
vector<vector<ll>>g2;
vector<ll>tin;
vector<ll>fup;
vector<ll>pare;
vector<bool>v;
ll timer=0;
map<pair<ll,ll>,bool>lel;
ll nodelluny=-1;
ll distancia=0;
ll edges=0;

ll find(ll x){
	if(pare[x]==x) return x;
	return pare[x]=find(pare[x]);
}

void unir(ll a, ll b){
	ll parea=find(a);
	ll pareb=find(b);
	if(parea!=pareb){
		pare[pareb]=parea;
	}
}

void dfs(ll x, ll parent){
	++timer;
	tin[x]=fup[x]=timer;
	for(ll adj:g[x]){
		if(!tin[adj]){
			dfs(adj,x);
			if(fup[adj]>tin[x]){
				lel[{x,adj}]=true;
				lel[{adj,x}]=true;
				++edges;
			}
			fup[x]=min(fup[x],fup[adj]);
		}else if(adj!=parent) fup[x]=min(fup[x],tin[adj]);
	}
}

void dfs2(ll x){
	v[x]=true;
	for(ll adj:g[x]){
		if(not v[adj] and not lel[{x,adj}]){
			unir(x,adj);
			dfs2(adj);
		}
	}
	
}

void dfs3(ll x, ll dist){
	v[x]=true;
	if(dist>distancia){
		distancia=dist;
		nodelluny=x;
	}
	for(ll adj:g2[x]){
		if(!v[adj]) dfs3(adj,dist+1);
	}
}


int main(){
	ll n,m;
	cin>>n>>m;
	g=vector<vector<ll>>(n);
	tin=vector<ll>(n);
	fup=vector<ll>(n);
	v=vector<bool>(n);
	pare=vector<ll>(n);
	while(m--){
		ll a,b; cin>>a>>b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0; i<n; ++i) pare[i]=i;
	dfs(0,-1);

	if(edges!=0){
		g2=vector<vector<ll>>(n);
		ll last=-1;
		for(ll i=0; i<n; ++i){
			if(!v[i]){
				dfs2(i);
				if(last!=-1){
				g2[last].push_back(find(i));
				g2[find(i)].push_back(last);
			  }
				last=find(i);
			}
		}
		v.assign(n,false);
		dfs3(last,0);
		distancia=0;
		v.assign(n,false);
		//cout<<nodelluny<<endl;
		dfs3(nodelluny,0);//LELELELELE
		//diametre=distancia
		cout<<edges+1-distancia<<endl;
	}else{
		cout<<0<<endl;
	}

}
