#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, p, d, c, k;
	cin >> t;
	while (t--) {
		cin >> p;
		int prov;
		vector<pair<int,char>>v;
		vector<int>port;
		for (int i = 0; i < p; ++i) {
			cin >> prov;
			port.push_back(prov);
		};
		cin >> d;
		vector<int>vd(d);
		for (int i = 0; i < d; ++i) {
			cin >> prov;
			v.push_back({prov, 2});
		};
		cin >> c;
		vector<int>vc(c);
		for (int i = 0; i < c; ++i) {
			cin >> prov;
			v.push_back({prov, 1});
		};
		cin >> k;
		vector<int>vk(k);
		for (int i = 0; i < k; ++i) {
			cin >> prov;
			v.push_back({prov, 0});
		};
		sort(port.begin(), port.end());
		sort(v.begin(), v.end());

		int res = port[port.size()-1];
		vector<int>sol(4, 0);
		for (int i = 0; i < 10; ++i) {
			auto x = v[v.size()-1];
			v.pop_back();
			res += x.first;
			++sol[x.second];
		}
		cout << res << " " << sol[2] << '-' << sol[1] << '-' << sol[0] << endl;
	}
}