#include <iostream>
using namespace std;

int main() {
	char a,b,c,d,e;
	a = b = c = d = '-';
	cin >> e;
	bool found = false;
	while (e != '.' and not found) {
		if (a == 'h' and b == 'e' and c == 'l' and d == 'l' and e == 'o') found = true;
		a = b;
		b = c;
		c = d;
		d = e;
		cin >> e;
	}
	cout << (found ? "hello" : "bye") << endl;
}