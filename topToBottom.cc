#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a > b) {
		a = a+b;
		b = a-b;
		a = a-b;
	}
	for (int i = b; i >= a; --i) cout << i << endl;
}