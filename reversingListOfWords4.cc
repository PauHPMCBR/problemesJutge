#include <iostream>
using namespace std;

int f(int n) {
	string s;
	int rem = n+1;
	while (cin >> s) {
		rem = f(n);
		if (rem > 0) cout << s << endl;
	}
	return rem-1;
}

int main() {
	int n;
	cin >> n;
	f(n);
}