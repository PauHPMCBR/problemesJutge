#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	if (a < b) {
		a = a+b;
		b = a-b;
		a = a-b;
	}
	if (a < c) {
		a = a+c;
		c = a-c;
		a = a-c;
	}
	if (b < c) {
		b = b+c;
		c = b-c;
		b = b-c;
	}
	for (int i = 0; i < 3; ++i) {
		char x;
		cin >> x;
		if (x == 'A') cout << c;
		else if (x == 'B') cout << b;
		else cout << a;
		if (i < 2) cout << ' ';
	}
	cout << endl;
}