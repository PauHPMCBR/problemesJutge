#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		string s;
		cin >> s;
		int a = 0, b = 0;
		for (int i = 2; i <= m; ++i) if (s[i-1] != 'L') ++a;
		for (int i = m; i < n; ++i) if (s[i-1] != 'R') ++b;
		cout << min(a, b) << endl;
	}
}