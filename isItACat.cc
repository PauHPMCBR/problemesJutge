#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		int stage = 0;
		for (int i = 0; i < n and stage >= 0; ++i) {
			if (stage == 0 and (s[i] == 'm' or s[i] == 'M')) continue;
			else if (stage == 1 and (s[i] == 'e' or s[i] == 'E')) continue;
			else if (stage == 2 and (s[i] == 'o' or s[i] == 'O')) continue;
			else if (stage == 3 and (s[i] == 'w' or s[i] == 'W')) continue;

			else if (stage == 0 and (s[i] == 'e' or s[i] == 'E')) ++stage;
			else if (stage == 1 and (s[i] == 'o' or s[i] == 'O')) ++stage;
			else if (stage == 2 and (s[i] == 'w' or s[i] == 'W')) ++stage;
			
			else stage = -1;
		}
		if (stage == 3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}