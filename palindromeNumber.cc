#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		if ((9*n < s) or (n%2 == 0 and s%2 != 0) or (s == 1 and n != 1)) cout << -1 << endl;
		else {
			int nines = s/18;
			int rest = n/2-nines;
			cout << string(nines, '9');
			if (rest != 0) cout << s/2-9*nines << string(rest-1, '0');
			if (n%2) cout << s-nines*18-(s/2-9*nines)*2;
			if (rest != 0) cout << string(rest-1, '0') << s/2-9*nines;
			cout << string(nines, '9');
			cout << endl;
		}
	}
}