#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	double c, i;
	int t;
	string s;
	cin >> c >> i >> t >> s;
	if (s == "simple") cout << c + c*i/100*t << endl;
	else {
		for (int j = 0; j < t; ++j) c *= 1 + i/100;
		cout << c << endl;
	}
}