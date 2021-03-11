#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
vector<ll>padre;
vector<ll>rango;
ll find(ll x){
  if(x==padre[x])return x;
  return padre[x]=find(padre[x]);
}
void unir(ll x, ll y){
  ll padrex=find(x);
  ll padrey=find(y);
  if(rango[padrex]>rango[padrey])padre[y]=padrex;
  else{
    padre[padrex]=padrey;
    if(rango[padrex]==rango[padrey]){
      rango[padrey]++;
    }
  }
}
bool conectats(ll p){
  for(ll i=0; i<p; ++i){
    if(find(i)!=find(0)) return false;
  }
  return true;
}
///////////////////////
int main() {
  ll t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    padre=vector<ll>(n);
    rango=vector<ll>(n);
    for(ll i=0; i<n; ++i){
      padre[i]=i;
    }
    vector<pair<ll,pair<ll,ll>>>v;
    for(ll i=0; i<m; ++i){
      ll x,y,w;
      cin>>x>>y>>w;
      v.push_back({w,{x,y}});
    }
    sort(v.begin(),v.end());
    ll solu=0;
    for(ll i=0; i<m; ++i){
      ll x=v[i].second.first;
      ll y=v[i].second.second;
      ll w=v[i].first;
      unir(x,y);
      solu=max(solu,w);
      if(conectats(n)) break;
    }
    cout<<solu<<endl;
  }
}