#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s>>t;
	int n = s.size();
	int l = t.size();
	int ans = 0;
	for(int i = 0;i<=n-l;i++){
		int check = 1;
		for(int j = 0;j<l;j++){
			if(s[j+i]==t[j]){
				check = 0;
				break;
			}
		}
		if(check)ans++;
	}
	cout<<ans<<endl;

}