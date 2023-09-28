#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, a, b, t;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		int rs = (a-2*b)*(a-2*b);
		//if (a-2*b < 0) rs = -1e9;
		vector<int>sols;
		int dist = 1e17;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			int d = a*a+b*b;
			if (d < dist) {
				if (dist > rs) {
					sols = vector<int>();
					dist = max(rs, d);
				}
			}
			if (d <= dist) sols.push_back(i);
		}

		cout << sols.size() << endl;
		for (auto i : sols) cout << i+1 << ' ';
		cout << endl;
	}
	
}