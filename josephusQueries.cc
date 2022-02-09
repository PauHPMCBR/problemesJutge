#include <bits/stdc++.h>
using namespace std;

int b(int n, int k) {
	if (n == 1) return 1;
	if (k <= (n+1)/2) {
		if (2*k > n) return 2*k-n;
		return 2*k;
	}
	return b(n/2, k - (n+1)/2)*2 - 1 + 2*(n%2);
}

int main(){
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << b(n, k) << endl;
	}
}