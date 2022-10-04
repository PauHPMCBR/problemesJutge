#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 0) cout << 0;
	while (n > 0) {
		if (n%16 < 10) cout << n%16;
		else cout << char('A' + n%16-10);
		n /= 16;
	}
	cout << endl;
}