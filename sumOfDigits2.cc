#include <iostream>
using namespace std;

int main() {
	int b;
	cin >> b;
	int n;
	while (cin >> n) {
		int m = n;
		int res = 0;
		while (m > 0) {
			res += m%b;
			m /= b;
		}
		cout << n << ": " << res << endl;
	}
}