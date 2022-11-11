#include <iostream>
using namespace std;

void canvi(int n, int b) {
	if (n >= b) canvi(n/b, b);
	if (n%b > 9) cout << char('A'+(n%b)-10);
	else cout << n%b;
}

int main() {
	int n;
	while (cin >> n) {
		cout << n << " = ";
		canvi(n, 2);
		cout << ", ";
		canvi(n, 8);
		cout << ", ";
		canvi(n, 16);
		cout << endl;
	}
}