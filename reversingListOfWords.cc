#include <iostream>
using namespace std;

void f() {
	string s;
	while (cin >> s) {
		f();
		cout << s << endl;
	}
}

int main() {
	f();
}