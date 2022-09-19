#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>dp(1e7);


int isPrime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 2;
	for (int i = 3; i * i <= n; i+=2) if (n % i == 0) return i;
	return 1; 
}

int main(){
	ll n = 1e7-1;
	for (ll i = 2; i < n; ++i) {
		ll prov = isPrime(i);
		if (prov == 1) dp[i] = 1;
		else {
			dp[i] = prov*dp[i/prov] + i/prov*dp[prov];
		}
		if (dp[i] == i) cout << i << " fixed" << endl;
	}
}