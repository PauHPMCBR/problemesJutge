#include <bits/stdc++.h>
using namespace std;

int main () {
	int counter = 0, n;
	bool couted = false;
	while (cin >> n) {
		++counter;
		if (n % 2 == 0 && !couted) {
			cout << counter << endl;
			couted = true;
		}
	}
}