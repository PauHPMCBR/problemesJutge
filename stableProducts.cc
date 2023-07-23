#include <iostream>
#include <vector>
using namespace std;

void print(int n, int b) {
	if (n == 0) return;
	print(n/b, b);
	if (n%b >= 10) cout << char('A'+(n%b)-10);
	else cout << n%b;
}

bool same_digits(int x, int y, int b) {
	vector<int>v(b);
	int z = x*y;
	while (x > 0) {
		++v[x%b];
		x /= b;
	}
	while (y > 0) {
		++v[y%b];
		y /= b;
	}
	while (z > 0) {
		--v[z%b];
		z /= b;
	}
	for (int i = 0; i < b; ++i) {
		if (v[i] != 0) return false;
	}
	return true;
}

int main() {
	int x, y;
	while (cin >> x >> y) {
		cout << "solutions for " << x << " and " << y << endl;
		bool foundSol = false;
		for (int base = 2; base <= 16; ++base) {
			if (same_digits(x, y, base)) {
				foundSol = true;
				print(x, base);
				cout << " * ";
				print(y, base);
				cout << " = ";
				print(x*y, base);
				cout << " (base " << base << ")" << endl;
			}
		}
		if (not foundSol) cout << "none of them" << endl;
		cout << endl;
	}
}