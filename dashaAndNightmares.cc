#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	vector<int>pows;
	pows.push_back(1);
	for (int i = 1; i < 27; ++i) pows.push_back(pows.back() *2);
	
	cin >> n;
	vector<int>odds;
	vector<int>oddsL;
	vector<int>evens;
	vector<int>evensL;
	for (int k = 0; k < n; ++k) {
		string s;
		cin >> s;

		vector<int>prov(27);
		for (char c : s) {
			++prov[c - 'a'];
		}

		int val = 0;
		int valL = 0;
		for (int i = 0; i < 27; ++i) {
			if (prov[i]%2) val += pows[i];
			if (prov[i]) valL += pows[i];
		}
		if (s.size()%2) {
			odds.push_back(val);
			oddsL.push_back(valL);
		}
		else {
			evens.push_back(val);
			evensL.push_back(valL);
		}
	}

	int ans = 0;

	for (int i = 0; i < odds.size(); ++i) {
		for (int j = 0; j < evens.size(); ++j) {
			if (__builtin_popcount(oddsL[i] | evensL[j]) == 25) {
				if (__builtin_popcount(odds[i] ^ evens[j]) == 25)
					++ans;
			}
		}
	}

	cout << ans << endl;
}