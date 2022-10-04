#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	m = n;
	int res = 0;
	while (m > 0) {
		m /= 10;
		++res;
	}
	if (n == 0) res = 1;
	cout << "The number of digits of " << n << " is " << res << '.' << endl;
}