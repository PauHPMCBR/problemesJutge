#include <iostream>
using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	if ((a == 'P' and b == 'A') or (a == 'A' and b == 'V') or (a == 'V' and b == 'P'))
		cout << 2 << endl;
	else if ((a == 'A' and b == 'P') or (a == 'V' and b == 'A') or (a == 'P' and b == 'V'))
		cout << 1 << endl;
	else cout << '-' << endl;
}