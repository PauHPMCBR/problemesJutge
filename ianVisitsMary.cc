#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t,a,b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == 1) {
			cout << 1 << endl << a << ' ' << b << endl;
		}
		else {
			cout << 2 << endl;
			cout << "1 " << b-1 << endl;
			cout << a << ' ' << b << endl;
		}
	}
}