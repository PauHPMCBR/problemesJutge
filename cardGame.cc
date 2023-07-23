#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>v(61 ,0);
vector<int>ans(61, 0);
int mod = 998244353;

int getxd(int n) {
	if (n == 0) return 0;
	if (ans[n] != 0) return ans[n];
	int sol = v[n]/2;//got best card
	sol += v[n-2]-getxd(n-2)-1; //got 2nd best
	return ans[n] = sol%mod;
}


signed main() {
	int t, n;
	cin >> t;
	v[2] = 2;
	for (int i = 4; i <= 60; i += 2) {
		v[i] = v[i-2] * (i-1)*2 / (i/2);
	}
	ans[2] = 1;
	while (t--) {
		cin >> n;
		int w = getxd(n);
		cout << w << ' ' << (v[n]-w-1+mod)%mod << ' ' << 1 << endl;
	}
}