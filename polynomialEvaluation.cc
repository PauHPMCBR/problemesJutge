#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	double x;
	cin >> x;
	double ans = 0;
	double xx = 1;
	double coef;
	while (cin >> coef) {
		ans += coef*xx;
		xx *= x;
	}
	cout << ans << endl;
}