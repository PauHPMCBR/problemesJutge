#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int p = n/7 + 1;
		int q = 0;
		while (7*p+4*q != n) {
			--p;
			while (7*p+4*q < n) ++q;
		}
		cout << p << ' ' << q << endl;
	}
}