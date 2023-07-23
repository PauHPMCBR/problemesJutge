#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool b = false;
		for (int i = 0; i < s.size()/2; ++i) {
			if (s[i] != s[0] or s[s.size()-i-1] != s[0]) {
				b = true;
				break;
			}
		}
		cout << (b ? "YES" : "NO") << endl;
	}
}