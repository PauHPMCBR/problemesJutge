#include <iostream>
using namespace std;

const int HEIGHT = 3143;

int main() {
	int a;
	int b = -1;
	int c = -1;
	cin >> c;
	if (c != 0) {
		cin >> b;
		if (b == 0) cout << "NO" << endl;
		else {
			bool found = false;
			cin >> a;
			while (a != 0) {
				if (b > c and b > a and b > HEIGHT) found = true;
				c = b;
				b = a;
				cin >> a;
			}
			cout << (found ? "YES" : "NO") << endl;
		}
	}
	else cout << "NO" << endl;
}