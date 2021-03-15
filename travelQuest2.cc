#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, m;
vector<pair<int,pair<int,int>>>v;
int f(int p){
    for(int i = 0;i<m;++i){
        if(v[i].second.first-1<=p && p<v[i].second.second-1){
            return v[i].first;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    v = vector<pair<int,pair<int,int>>>(m);
    for(int j = 0;j<m; ++j){
        cin>>v[j].second.first>>v[j].second.second>>v[j].first;
    }
    sort(v.begin(),v.end());
    int c = 0;
    for(int i = 0;i<n-1;++i){
        c = max(c,f(i));
    }
    cout<<c<<endl;
}