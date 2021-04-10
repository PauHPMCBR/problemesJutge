#include <bits/stdc++.h>
using namespace std;

int suma_digits(int x) {
	int res = 0;
	while (x > 0) {
		res += x%10;
		x /= 10;
	}
	return res;
}

int reduccio_digits(int x) {
	if (x < 10) return x;
	return reduccio_digits(suma_digits(x));
}

int main() {
	int n;
	cin >> n;
	cout << reduccio_digits(n) << endl;
}