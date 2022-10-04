#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	int zeros = 0;
	while (n%10 == 0 and n != 0) {
		n /= 10;
		++zeros;
	}
	while (n > 0) {
		res *= 10;
		res += n%10;
		n /= 10;
	}
	for (int i = 0; i < zeros; ++i) cout << '0';
	cout << res << endl;
}