#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s.size() == 1) {cout << s << endl; continue;}
		if (s.size() == 2) {
			if (s[1] > s[0]) cout << s[1] << s[0] << endl;
			else cout << s << endl;
			continue;
		}
		vector<int>v(27);
		int largest = 0;
		for (char c : s) {
			++v[c - 'a'];
			largest = max(largest, (int)c-'a');
		}
		int carry = -1;
		vector<int>v1(27);
		vector<int>v2(27);

		bool printed = false;
		for (int i = 0; i <= largest and !printed; ++i) {
			if (v[i] == 0) continue;
			if (carry != -1) {
				if (i == largest) {
					v1[i] += v[i]/2;
					v2[i] = v1[i];

					for (int j = 0; j < 27; ++j) cout << string(v1[j], 'a'+j);
					if (v[i]%2) cout << char('a'+i);
					cout << char('a' + carry);
					for (int j = 26; j >= 0; --j) cout << string(v2[j], 'a'+j);
					cout << endl;
					printed = true;
				}
				else {
					for (int j = 0; j < i; ++j) cout << string(v1[j], 'a'+j);
					for (int j = i; j < 27; ++j) cout << string(v[j], 'a'+j);
					cout << char('a' + carry);
					for (int j = i; j >= 0; --j) cout << string(v2[j], 'a'+j);
					cout << endl;
					printed = true;
				}
			}

			v1[i] += v[i]/2;
			v2[i] = v1[i];
			if (v[i]%2 != 0) {
				carry = i;
			}
		}
		if (!printed) {
			for (int j = 0; j < 27; ++j) cout << string(v1[j], 'a'+j);
			if (carry != -1) cout << char('a' + carry);
			for (int j = 26; j >= 0; --j) cout << string(v2[j], 'a'+j);
			cout << endl;
		}
	}
}