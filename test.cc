#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i+=2) if (n % i == 0) return false;
	return true; 
}

int main() {
	int n = 1e7;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (isPrime(i)) ++ans;
	}
	cout << ans << endl;
}