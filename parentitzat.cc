#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int n = 0;
	bool failed = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++n;
		else --n;
		if (n < 0) failed = true;
	}
	if (n != 0 || failed) cout << "no" << endl;
	else cout << "si" << endl;
}
