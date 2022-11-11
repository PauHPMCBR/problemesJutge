#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int length = log10(n)+1;
	if (n == 0 or length%2 == 1) cout << "nothing" << endl;
	else {
		int x = 0;
		int y = 0;
		for (int i = 0; i < length/2; ++i) {
			y += n%10;
			n /= 10;
		}
		for (int i = 0; i < length/2; ++i) {
			x += n%10;
			n /= 10;
		}
		if (x < y) cout << x << " < " << y << endl;
		else if (x > y) cout << x << " > " << y << endl;
		else cout << x << " = " << y << endl;

	}
}