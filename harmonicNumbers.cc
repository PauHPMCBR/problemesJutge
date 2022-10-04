#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
    cout.precision(4);
	int n;
	cin >> n;
	double res = 0;
	for (int i = 1; i <= n; ++i) res += 1/double(i);
	cout << res << endl;
}