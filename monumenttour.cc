#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;

int n;
int main() {
	int X,Y;
	cin>>X>>Y;
	cin>>n;
	map<int,int>m1;
	map<int,int>m2;
	vector<int>x(n);
	vector<int>y(n);
	vector<pair<int,int>>v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].second>>v[i].first;
		if(m1[v[i].second]){
			m1[v[i].second] = min(v[i].first,m1[v[i].second]);
			m2[v[i].second] = max(v[i].first,m2[v[i].second]);
		}
		else{
			m1[v[i].second] = v[i].first;
			m2[v[i].second] = v[i].first;
		}
	}
	vector<pair<int,int>>v2;
	for(auto x : m1){
		int dx = x.first;
		int dy = x.second;
		v2.push_back({dy,dx});
	}
	for(auto x : m2){
		int dx = x.first;
		int dy = x.second;
		v2.push_back({dy,dx});
	}
	sort(v2.begin(),v2.end());
	for(int i = 0;i<n;i++){
		x[i] = v2[i].second;
		y[i] = v2[i].first;
	}
	int cost = X-1;
	int currdown = 0;
	int currup = m1.size();

	int ans = cost;

	int p = y[0];
	for(int i = 1;i<n;i++){
		int d = y[i]-y[i-1];
		cost +=2*currdown*d;
		cost-=2*currup*d;
		if(m1[x[i]]==m2[x[i]])currup--;
		currdown++;
		ans = min(ans, cost);
	}
	cout<<ans<<endl;
}