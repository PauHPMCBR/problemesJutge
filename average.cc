#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	double res = 0;
	double x;
	int nums = 0;
	while (cin >> x) {
		++nums;
		res += x;
	}
	cout << res/nums << endl;
}