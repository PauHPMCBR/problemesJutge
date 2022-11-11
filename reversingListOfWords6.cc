#include <iostream>
using namespace std;

int f(int n) {
	string s;
	while (cin >> s) {
		int rem = f(n+1);
		if (rem > 0) cout << s << endl;
		return rem+1;
	}
	return -(n-1)/2;
}

int main() {
	f(0);
}