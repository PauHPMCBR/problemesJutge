#include <bits/stdc++.h>
using namespace std;

void divisors(int n, int i) {
	if (i*i > n) return;
	for (; i*i <= n; ++i) {
		if (n%i == 0) break;
	}
	if (n%i == 0) {
		cout << i << ' ';
		if (i*i != n) {
			divisors(n, i+1);
			cout << n/i << ' ';
		}
	}
}

int main(){
	int n;
	while (cin >> n) {
		if (n == 1) cout << "divisors de 1: 1" << endl;
		else {
			cout << "divisors de " << n << ": 1 ";
			divisors(n, 2);
			cout << n << endl;
		}
	}
}