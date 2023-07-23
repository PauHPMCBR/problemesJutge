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
		vector<pair<int,int>>v;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov;
			if (prov != 0) v.push_back({prov,i});
		}
		if (v.size()%2 != 0) {
			cout << -1 << endl;
			continue;
		}
		if (v.size() == 0) {
			cout << 1 << endl << "1 " << n << endl;
			continue;
		}
		
		vector<int>sol;
		for (int i = 0; i < v.size(); i += 2) {
			if (v[i].first == v[i+1].first) {
				if (abs(v[i].second - v[i+1].second)%2 == 1) sol.push_back(v[i].second);
				else {
					sol.push_back(v[i].second);
					sol.push_back(v[i].second+1);
				}
			}
			else {
				if (abs(v[i].second - v[i+1].second)%2 == 0) sol.push_back(v[i].second);
				else {
					sol.push_back(v[i].second);
					sol.push_back(v[i].second+1);
				}
			}
		}
		cout << sol.size() << endl;
		for (int i = 0; i < sol.size(); ++i) {
			cout << sol[i]+1 << ' ';
			int p2;
			if (i != sol.size()-1) p2 = sol[i+1];
			else p2 = n;
			cout << p2 << endl; 
		}
	}
}
