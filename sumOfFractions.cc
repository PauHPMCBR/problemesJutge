#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	int a, b, k;
	while (cin >> a >> b >> k) {
		double res = 0;
		for (int i = a; i <= b; i += k) {
			res += 1/double(i);
		}
		cout << res << endl;
	}
}