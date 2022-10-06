#include <iostream>
using namespace std;

int main() {
	string s1 = "";
	string s2 = "";
	string s;
	while (cin >> s) {
		if (s > s2) {
			if (s > s1) {
				s2 = s1;
				s1 = s;
			}
			else if (s1 != s) s2 = s;
		}
	}
	cout << s2 << endl;
}