#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=10^9+7;


ll powermod(ll x, ll y) {
    ll res=1;
    while(y>0) {
        if (y&1)
            res=res*x%mod;

        x=x*x%mod;
        y=y>>1;
    }
    return res;
}

int main() { 
	int t;
	cin >> t;
	while (t--) {
		ll n ;
		cin >> n;
		cout<<powermod(2,n+1)-n-2<<endl;
	}
}