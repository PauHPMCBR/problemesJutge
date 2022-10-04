#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(6);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "rectangle") {
			double a, b;
			cin >> a >> b;
			cout << a*b << endl;
		}
		else {
			double r;
			cin >> r;
			cout << M_PI*r*r << endl;
		}
	}
}