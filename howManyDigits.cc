#include <iostream>
using namespace std;

int main() {
	int b, n;
	while (cin >> b >> n) {
		int res = 0;
		while (n > 0) {
			n /= b;
			++res;
		}
		cout << res << endl;
	}
}