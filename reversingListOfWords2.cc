#include <iostream>
using namespace std;

void f() {
	string s;
	cin >> s;
	if (s == "end") return;
	f();
	cout << s << endl;
}

int main() {
	f();
}