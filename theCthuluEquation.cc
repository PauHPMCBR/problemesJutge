#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long double ld;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h,w,p;
	ld s;
	while (cin >> h >> w >> s >> p) {
		if (h == 0) break;
		vector<pair<int,int>>pers;
		pair<int,int>r;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				char c;
				cin >> c;
				if (c == 'R') r = {i,j};
				else if (c == 'P') pers.push_back({i,j});
			}
		}
		int xd = 0;
		vector<ld>tolerance(p);
		for (int i = 0; i < p; ++i) {
			cin >> tolerance[i];
			ld rs = (pers[i].first - r.first)*(pers[i].first - r.first) + 
				(pers[i].second - r.second)*(pers[i].second - r.second);
				rs *= s*s;

			ld field = (ld)4.15287 * (ld)(1.91123*1e10) / rs;
			if (field > tolerance[i]) ++xd;

		}
		cout << xd << endl;

	}
}