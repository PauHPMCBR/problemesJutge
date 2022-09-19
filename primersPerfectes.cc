#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i*i <= n; i += 2) if (n % i == 0) return false;
		return true;
}

bool es_primer_perfecte(int n) {
	if (n < 10) return isPrime(n);
	if (!isPrime(n)) return false;
	int res = 0;
	while (n > 0) {
		res += n%10;
		n /= 10;
	}
	return es_primer_perfecte(res);
}

int main() {
	int n;
	cin >> n;
	cout << es_primer_perfecte(n) << endl;
}