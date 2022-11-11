#include <iostream>
using namespace std;

int f() {
	char c;
	cin >> c;
	if (c <= '9' and c >= '0') return c-'0';
	if (c == '+') return f() + f();
	if (c == '-') return f() - f();
	return f() * f();
}

int main() {
	cout << f() << endl;
}