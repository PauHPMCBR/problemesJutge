#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n < 10) cout << "The product of the digits of " << n << " is " << n << "." << endl;
		else while (n > 9) {
			cout << "The product of the digits of " << n << " is ";
			int m = 1;
			while (n > 0) {
				m *= n%10;
				n /= 10;
			}
			cout << m << "." << endl;
			n = m;
		}
		cout << "----------" << endl;
	}
}