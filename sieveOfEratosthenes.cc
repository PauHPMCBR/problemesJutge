#include <iostream>
#include <vector>
using namespace std;

void sieve(vector<bool>& v, int n) {
	for (int i = 2; i <= n; ++i) {
		if (v[i]) {
			for (int j = 2*i; j <= n; j += i) v[j] = 0;
		}
	}
}

int main() {
	int n = 1e6+1;
	vector<bool>isPrime(n+1, 1);
	isPrime[0] = 0;
	isPrime[1] = 0;
	sieve(isPrime, n);
	int q;
	while (cin >> q) cout << q << (isPrime[q] ? " is prime" : " is not prime") << endl;
}