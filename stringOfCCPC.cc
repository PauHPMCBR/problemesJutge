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
		if (n < 3) {
			cout << 0 << endl;
			continue;
		}
		int sol = 0;
		bool almost = false;

		if (s[0] == 'C' && s[1] == 'P' && s[2] == 'C') almost = true;
		if (s[n-3] == 'C' && s[n-2] == 'C' && s[n-1] == 'P') almost = true;
		if (s[n-3] == 'C' && s[n-2] == 'C' && s[n-1] == 'C') almost = true;

		for (int i = 0; i < n-3; ++i) {
			if (s[i] == 'C' && s[i+1] == 'C' && s[i+2] == 'P' && s[i+3] == 'C') {
				++sol;
				continue;
			}

			if (s[i] == 'P' && s[i+1] == 'C' && s[i+2] == 'P' && s[i+3] == 'C') almost = true;
			if (s[i] == 'C' && s[i+1] == 'C' && s[i+2] == 'P' && s[i+3] == 'P') almost = true;
			if (i != 0)
				if (s[i-1] == 'C' && s[i] == 'C' && s[i+1] == 'C') almost = true;
		}

		if (almost) cout << sol+1 << endl;
		else cout << sol << endl;
	}
}