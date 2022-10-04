#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int m = n;
		int res = 0;
		while (n > 0) {
			res += n%10;
			n /= 10;
		}
		cout << "The sum of the digits of " << m << " is " << res << '.' << endl;
	}
}