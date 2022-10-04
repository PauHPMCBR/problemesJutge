#include <iostream>
using namespace std;

int main() {
	char c;
	int res = 0;
	while (cin >> c) {
		if (c == 'a') ++res;
	}
	cout << res << endl;
}