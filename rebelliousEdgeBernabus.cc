#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e8;
const int maxN = 2e6+5;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323;
vector<vector<pair<int,int>>>g;
vector<vector<pair<int,int>>>h;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a = -1;
		int b = -1;
		int special = -1;
		g = vector<vector<pair<int,int>>>(n);
		h = vector<vector<pair<int,int>>>(n);
		for(int i = 0;i<m;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			int w;
			cin>>w;
			
			if(v<u){
				a = v;
				b = u;
				special = w;
			}
			else{
				g[u].push_back({v,w});
				h[v].push_back({u,w});
			}
		}
		int ans1 = 0;
		for(int i = 1;i<n;i++){
			int best = INF;
			for(auto [u,w] : h[i]){
				if(u>i)continue;
				best = min(best, w);
			}
			ans1+=best;
		}
		if(a==0){
			cout<<ans1<<endl;
			continue;
		}
		vector<int>dp(n);
		vector<int>par(n,-1);
		dp[0] = 0;
		par[0]= 0;
		for(int i = 1;i<a;i++){
			dp[i] = INF;
			for(auto [u,w] : h[i]){
				if(dp[i]>w+dp[u]){
					par[i] = u;
					dp[i] = w+dp[u];
				}
			}
		}
		dp[a] = -1;
		for(int i = a+1;i<=b;i++){
			dp[i]= INF;
			for(auto [u,w] : h[i]){
				if(u==a)continue;
				if(dp[i]>w+dp[u]){
					par[i] = u;
					dp[i] = w+dp[u];
				}
			}
		}
		vector<int>used(n,0);
		if(par[b]==-1){
			cout<<ans1<<endl;
			continue;
		}
		int v= b;
		used[b] = 1;
		while(v!=0){
			used[v] = 1;
			v = par[v];
		}
		used[a] = 1;
		int ans2 = dp[b]+special;
		for(int i = 1;i<n;i++){
			if(used[i])continue;
			int best = INF;
			for(auto [u,w] : h[i]){
				if(u>i)continue;
				best = min(best, w);
			}
			ans2+=best;
		}
		cout<<min(ans1,ans2)<<endl;

	}
}