#include <iostream>
using namespace std;

int main() {
	int x = 0;
	int y = 0;
	char c;
	while (cin >> c) {
		if (c == 'n') --y;
		else if (c == 's') ++y;
		else if (c == 'e') ++x;
		else --x;
	}
	cout << '(' << x << ", " << y << ')' << endl;
}