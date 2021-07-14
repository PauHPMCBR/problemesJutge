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
	
	int res = 0, n2 = n;
	while (n > 0) {
		res += n%10;
		n /= 10;
	}
	if (!es_primer_perfecte(res)) return false;
    return isPrime(n2);
}

int main() {
	int n;
	cin >> n;
	cout << es_primer_perfecte(n) << endl;
}
