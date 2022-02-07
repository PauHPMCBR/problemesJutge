#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans = 0;
void f(vector<bool>v, ll m) {
	if (m == 0) return;
	vector<bool>v2;
	for (ll i = 0; i < v.size(); i += 2) {
		if (v[i] && v[i+1]) ++ans;

		if (v[i] || v[i+1]) v2.push_back(1);
		else v2.push_back(0);
	}
	f(v2, m-1);
}

int main(){
	ll n, m;
	while (cin >> n >> m) {
		ans = 0;
		if (n == 0) return 0;
		vector<bool>v(n);
		char prov;
		for (ll i = 0; i < n; ++i) {cin >> prov; v[i] = (prov=='1');}
		f(v, m);
		cout << ans << endl;
	}
}