#include <iostream>
#include <math.h>
using namespace std;

int intlog(int base, int x) {
	if (base == 10) return log10(x);
    return (int)(log(x) / log(base));
}


int main() {
	int b, n;
	while (cin >> b >> n) {
		cout << intlog(b, n) << endl;
	}
}