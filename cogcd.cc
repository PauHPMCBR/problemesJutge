#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> t;
	while (t--) {
	cin >> n;
	/*for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (__gcd(i*j,n) != __gcd(i,n) * __gcd(j,n)) cout << i << ' ' << j << endl;
			//cout << i << ' ' << __gcd(i,n) << "  " << j << ' ' << __gcd(j,n) << "  " << __gcd(i,n)*__gcd(j,n) << ' ' << __gcd(i*j,n) << endl;
		}
	}*/
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		int prov = __gcd(i,n);
		if (prov == 1) continue;
		for (int j = i; j <= n; j += prov) {
			if (__gcd(j,n)*prov != __gcd(i*j, n)) ++count;
		}
	}
	cout << (n*(n+1)/2) - count << endl;
}
}