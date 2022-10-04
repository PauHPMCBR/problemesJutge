#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	int n, m;
	while (cin >> n >> m) {
		double res = 0;
		for (int i = m+1; i <= n; ++i) {
			res += 1/double(i);
		}
		cout << res << endl;
	}
}