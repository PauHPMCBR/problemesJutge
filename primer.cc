#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i+=2) if (n % i == 0) return false;
	return true; 
}

int main () {
	int n;
	while (cin >> n) {
		if (!isPrime(n)) return 1;
		if (n == 2) cout << 3 << endl;
		else {
			int i = n+2;
			while (!isPrime(i)) i += 2;
			cout << i << endl;
		}
	}
}