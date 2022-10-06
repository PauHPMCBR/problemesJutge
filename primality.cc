#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		bool isPrime = true;
		if (x < 2) isPrime = false;
		int j = 2;
		while (j*j <= x and isPrime) {
			if (x%j == 0) isPrime = false;
			++j;
		}
		cout << x << (isPrime ? " is prime" : " is not prime") << endl;
	}
}