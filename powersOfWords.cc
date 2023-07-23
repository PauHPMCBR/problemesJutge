#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (cin >> s) {
		vector<int>v(26);
		for (char c : s) {
			++v[c - 'a'];
		}
		int x = 0;
		for (int i = 0; i < 26; ++i) {
			if (v[i] == 0) continue;
			if (x == 0) x = v[i];
			else x = gcd(x, v[i]);
		}

		if (x == 1) cout << "NO" << endl;
		else {
			for (int i = 2; i*i <= x; ++i) {
				if (x%i == 0) {
					x = i;
					break;
				}
			}

			string a = "";
			for (int i = 25; i >= 0; --i) {
				a += string(v[i]/x, char('a' + i));
			}

			for (int i = 0; i < x; ++i) cout << a;
			cout << endl;
		}
	}
}