#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
ll n;
vector<ll>v;

ll b(ll pos) {
	if (pos > n+1) return 0;
	if (pos >= n) return 1;
	if (v[pos] != -1) return v[pos];
	return v[pos] = (b(pos+2) + b(pos+3) + b(pos+1))%MOD;
}

int main(){
	cin >> n;
	v = vector<ll>(n, -1);
	cout << b(0) << endl;
}