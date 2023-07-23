#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int,int>>bonus;
		set<int>heros;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov;
			if (prov == 0) heros.insert(i);
			else bonus.push_back({prov, i});
		}
		sort(bonus.begin(), bonus.end(), greater<>());
		int res = 0;

		for (auto i : bonus) {
			if (heros.empty()) break;
			if (i.second > *heros.rbegin()) continue;
			
			heros.erase(lower_bound(heros.begin(), heros.end(), i.second));
			res += i.first;
		}

		cout << res << '\n';
	}
}