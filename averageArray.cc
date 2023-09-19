#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int,int>>sol;
		unordered_map<int,int>odd;
		unordered_map<int,int>even;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov;
			if (prov%2 == 0) ++even[prov];
			else ++odd[prov];
		}

		bool possible = true;
		while (even.size() + odd.size() > 1) {
			if (odd.size() >= 2) {
				int a = (*odd.begin()).first;
				--(*odd.begin()).second;
				if ((*odd.begin()).second == 0) odd.erase(odd.begin());

				int b = (*odd.begin()).first;
				--(*odd.begin()).second;
				if ((*odd.begin()).second == 0) odd.erase(odd.begin());

				sol.push_back({a,b});
				int c = (a+b)/2;
				if (c%2 == 0) ++even[c];
				else ++odd[c];
			}

			else if (even.size() >= 2) {
				int a = (*even.begin()).first;
				--(*even.begin()).second;
				if ((*even.begin()).second == 0) even.erase(even.begin());

				int b = (*even.begin()).first;
				--(*even.begin()).second;
				if ((*even.begin()).second == 0) even.erase(even.begin());

				sol.push_back({a,b});
				int c = (a+b)/2;
				if (c%2 == 0) ++even[c];
				else ++odd[c];
			}

			else {
				possible = false;
				cout << -1 << endl;
				break;
			}
		}

		if (possible) {
			for (auto i : sol) cout << i.first << ' ' << i.second << endl;
		}
	}
}