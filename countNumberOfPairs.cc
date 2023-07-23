#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int>v(27);
		vector<int>w(27);
		for (char c : s) {
			if (c >= 'a' and c <= 'z') ++v[c - 'a'];
			else ++w[c - 'A'];
		}

		int b = 0, bb = 0;
		for (int i = 0; i < 27; ++i) {
			b += min(v[i], w[i]);
			bb += abs(v[i] - w[i])/2;
		}

		cout << b + min(k, bb) << endl;
	}
}