#include <iostream>
using namespace std;


int main() {
	string s;
	cin >> s;
	int open = 0;
	bool failed = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++open;
		else --open;
		if (open < 0) failed = true;
	}
	if (open != 0 or failed) cout << "no" << endl;
	else cout << "yes" << endl;
}