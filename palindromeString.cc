#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool sus = true;
		for (int i = 1; i < s.size(); ++i) if (s[0] != s[i]) {
			sus = false;
			break;
		}
		if (!sus) cout << s.size()-1 << endl;
		else cout << -1 << endl;
	}
}