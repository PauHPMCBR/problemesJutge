#include <iostream>
using namespace std;

int main() {
	char c;
	int res = 0;
	cin >> c;
	while (c != '.') {
		if (c == 'a') ++res;
		cin >> c;
	}
	cout << (res > 0 ? "yes" : "no") << endl;
}