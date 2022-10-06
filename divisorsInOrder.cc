#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		cout << "divisors of " << n << ":";
		if (n == 1) cout << " 1" << endl;
		else {
			for (int i = 1; i*i < n; ++i) {
				if (n%i == 0) {
					cout << ' ' << i;
				}
			}
			for (int i = sqrt(n+1); i > 0; --i) {
				if (n%i == 0) {
					cout << ' ' << n/i;
				}
			}
			cout << endl;
		}
	}
}