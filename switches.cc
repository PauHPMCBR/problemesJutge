#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int l;
	cin>>l;
	
	vector<int>b(m,0);
	for(int i = 0;i<l;i++){
		int k;
		cin>>k;
		b[k-1] = 1;
	}
	int cnt = l;
	vector<vector<int>>a(n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			int p;
			cin>>p;
			a[i].push_back(p-1);
		}
	}
	if(cnt==0){
		cout<<0<<endl;
		return 0;
	}
	int i = 0;
	while(i<2*n){
		for(auto x : a[i%n]){
			if(b[x]==1)cnt--;
			else cnt++;
			b[x] = 1-b[x];
		}
		if(cnt==0){
			cout<<i+1<<endl;
			return 0;
		}
		i++;
	}
	cout<<-1<<endl;

}