#include <bits/stdc++.h>
using namespace std;

bool almostPrime (int n) {
	if (n < 4) return false;
	int primes = 0;
	for (int i = 2; i*i <= n; ++i) {
		while (n%i == 0) {
			if (i*i == n) {
				++primes;
				//cout << i << endl;
				if (primes > 2) return false;
				n = 1;
			}
			else {
				++primes;
				n /= i;
				//cout << i << endl;
				if (primes > 2) return false;
			}
		}
	}
	if (n != 1) ++primes;
	return primes == 2 ? true : false;
}

int main() {
	int n;
	cin >> n;
	if (almostPrime(n)) cout << "YES" << endl;
	else cout << "NO" << endl;
}