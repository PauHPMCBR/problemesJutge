#include <iostream>
using namespace std;

int main() {
	int d, n, t;
	cin >> d >> n >> t;
	int res = 0;
	for (int i = 0; i < t; ++i) {
		int x;
		cin >> x;
		n += x;
		n -= d;
		if (n > 0) ++res;
	}
	cout << res << endl;
}