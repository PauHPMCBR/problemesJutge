#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	cin >> n;
	double sum1 = 0;
	double sum2 = 0;
	for (int i = 0; i < n; ++i) {
		double x;
		cin >> x;
		sum1 += x*x;
		sum2 += x;
	}
	cout << 1/double(n-1)*sum1 - 1/double(n*(n-1))*sum2*sum2 << endl;
}