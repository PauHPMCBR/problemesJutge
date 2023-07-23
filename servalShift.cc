#include <bits/stdc++.h>
using namespace std;

int t, n;
string a,b;

int firstOne(string& s) {
	for (int i = 0; i < n; ++i)
		if (s[i] == '1') return i;
	return -1;
}

void update(int shift) {
	string s = a;
	for (int i = 0; i < n; ++i) {
		if (i+shift < 0 or i+shift >= n) continue;
		if (a[i] == a[i+shift]) s[i] = '0';
		else s[i] = '1';
	}
	a = s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b;

		if (firstOne(b) == -1) {
			if (firstOne(a) == -1) cout << 0 << endl;
			else cout << -1 << endl;
		}
		else {
			if (firstOne(a) == -1) cout << -1 << endl;
			else {
				cout << n << endl;
				int updates = 0;
				for (int i = 0; i < n; ++i) {
					if (b[i] != a[i]) {
						int x = firstOne(a);
						if (x == i) {
							a[i] = '0';
							x = firstOne(a);
							a[i] = '1';
						}
						int k = x - i;
						cout << k << " ";
						cout << endl << a << endl;
						++updates;
						update(k);
					}
				}
				for (int i = updates; i < n; ++i) cout << n << " ";
				cout << endl;
			}
		}
	}
}