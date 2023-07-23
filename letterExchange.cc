#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n;
vector<pair<int,int>>v;
vector<vector<int>>sol;



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		v = vector<pair<int,int>>(n);
		for (int i = 0; i < n; ++i) {
			v[i] = {0,i};
			string s;
			cin >> s;
			for (char c : s) {
				if (c == 'w') v[i].first += 100;
				else if (c == 'i') v[i].first += 10;
				else v[i].first += 1;
			}
		}
		sol = vector<vector<int>>(0);
		sort(v.begin(), v.end());
		int p1 = 0, p2 = n-1;
		while (v[p2].first > 200) {
			if (v[p1].first >= 20) {
				v[p1].first += 90;
				v[p2].first -= 90;
				sol.push_back({v[p1].second, 10, v[p2].second, 100});
			}
			else {
				v[p1].first += 99;
				v[p2].first -= 99;
				sol.push_back({v[p1].second, 1, v[p2].second, 100});
			}
			++p1;
			--p2;
		}

		sort(v.begin(), v.end());
		p1 = 0, p2 = n-1;
		while (v[p2].first > 200) {
			if (v[p1].first >= 20) {
				v[p1].first += 90;
				v[p2].first -= 90;
				sol.push_back({v[p1].second, 10, v[p2].second, 100});
			}
			else {
				v[p1].first += 99;
				v[p2].first -= 99;
				sol.push_back({v[p1].second, 1, v[p2].second, 100});
			}
			++p1;
			--p2;
		}


		sort(v.begin(), v.end());
		p1 = 0, p2 = n-1;
		while (v[p1].first < 110) {
			if (v[p2].first <= 111) --p2;
			v[p1].first += 9;
			v[p2].first -= 9;
			sol.push_back({v[p1].second, 1, v[p2].second, 10});
			++p1;
		}
		cout << sol.size() << endl;
		for (auto i : sol) {
			cout << i[0]+1 << ' ';
			if (i[1] == 100) cout << 'w';
			else if (i[1] == 10) cout << 'i';
			else cout << 'n';
			cout << ' ' << i[2]+1 << ' ';
			if (i[3] == 100) cout << 'w';
			else if (i[3] == 10) cout << 'i';
			else cout << 'n';
			cout << endl;
		}
	}
}