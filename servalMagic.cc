#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		int start = -1;
		int end = -1;

		bool possible = true;
		for (int i = 0; i < s.size()/2; ++i) {
			if (s[i] != s[n-i-1]) {
				if (start == -1) start = i;
				else if (end != -1) {
					possible = false;
					break;
				}
			}
			else {
				if (start != -1) {
					if (end == -1) end = i;
				}
			}
		}
		if (possible) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}