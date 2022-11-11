#include <iostream>
using namespace std;

char encoded(char c, int k) {
	if (c == '_') return ' ';
	if (c < 'a' or c > 'z') return c;
	int x = c-'a';
	x = (x+k)%26;
	return char('A'+x);
}

int main() {
	int k;
	while (cin >> k) {
		string s;
		cin >> s;
		for (char c : s) if (c != '.') cout << encoded(c, k);
		cout << endl;
	}
}