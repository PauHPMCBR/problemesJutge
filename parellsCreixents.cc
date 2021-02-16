#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int zdf = 0; zdf < n; ++zdf) {
		int p1, p2;
		cin >> p1;
		int counter = 0;
		if (p1 != 0) {
			while (cin >> p2) {
				if (p2 == 0) break;
				if (p2 > p1) ++counter;
				p1 = p2;
			}
		}
		cout << counter << endl;
	}
}