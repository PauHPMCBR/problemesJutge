#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;
vector<int>factorials(1e5+1);

int power(int x, int y, int M) {
    if (y == 0) return 1;
 
    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}


signed main() {
	factorials[0] = 1;
	factorials[1] = 1;
	for (int i = 2; i <= 1e5; ++i) {
		factorials[i] = (factorials[i-1] * i)%mod;
	}

	int n, k;
	cin >> n >> k;
	if (k < n) {
		int ans = 0;
		for (int i = 0z; i <= k; ++i) {
			ans += (factorials[n] * power((factorials[i] * factorials[n-i])%mod, mod-2, mod))%mod;
			ans %= mod;
		}
		cout << ans << endl;
	}
	else cout << power(2, n, 1e9+7) << endl;
}