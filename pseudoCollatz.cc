#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int x, y, n;
	while (cin >> x >> y >> n) {
		vector <int> v(1e6 + 1, -1);
	int round = 0;
	while (n <= 1e6) {
		if (v[n] != -1) {
			cout << round-v[n] << endl;
			break;
		}
		else {
			v[n] = round;
			if (n%2 == 0) n = n/2 + x;
			else n = n*3 + y;
		}
		++round;
	}
	if (n > 1e6) cout << n << endl;
}
}