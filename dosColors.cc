#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>>G;
vector<int>c;
vector<bool>v;
bool posible=true;
 
 
void dfs(int x, int color){
    c[x]=color;
    v[x]=true;
    if(not posible) return;
    for(int adj:G[x]){
        if(c[adj]==color and v[adj]){
            posible=false;
            break;
        }
        if(v[adj]) continue;
        dfs(adj,!color);
    }
 
}

int main(){
    int n,m;
    while (cin>>n>>m) {
    G=vector<vector<int>>(n);
    c=vector<int>(n,-1);
    v=vector<bool>(n);
    posible = true;
     int a,b;
     while(m--){
         cin>>a>>b;
         G[a].push_back(b);
         G[b].push_back(a);
     }
     for(int i=0; i<n and posible; ++i){
         if(!v[i]) dfs(i,0);
     }
     if(not posible) cout<<"no"<<endl;
     else{
         cout << "yes" << endl;
     }
 }
}