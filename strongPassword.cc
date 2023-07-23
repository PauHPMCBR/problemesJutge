#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s, l, r;
		int m;
		cin >> s >> m >> l >> r;
		bool possible = false;
		
		int pos = 0;
		for (int i = 0; i < m and not possible; ++i) {
			if (pos == s.size()) {
				possible = true;
				break;
			}
			//cout << pos << endl;
			vector<bool>v(10, false);
			int available = r[i] - l[i] + 1;
			while (available > 0) {
				//cout << pos << ' ' << available << endl;
				if (s[pos] <= r[i] and s[pos] >= l[i]) {
					int x = s[pos] - '0';
					if (!v[x]) {
						--available;
						v[x] = true;
					}
				}
				++pos;
				if (pos == s.size()) {
					if (available != 0) possible = true;
					break;
				}
			}
		}

		cout << (possible ? "YES" : "NO") << endl;
	}
}