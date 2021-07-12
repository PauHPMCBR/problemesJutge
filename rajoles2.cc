#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll pb,pv,n;
	while (cin >> pb >> pv >> n) {
		string s;
		cin >> s;

		if (s.size() < 3) {
			cout << 0 << endl;
			continue;
		}

		vector<ll>b(n);
		vector<ll>v(n);
		b[0] = (s[0] == 'B') ? 0 : pb;
		for (ll i = 1; i < n; ++i) {
			b[i] = b[i-1] + (s[i] == 'V')*pb;
		}

		v[n-1] = (s[n-1] == 'V') ? 0 : pv;
		ll minCost1 = b[n-2]+v[n-1];

		for (ll i = n-2; i >= 0; --i) {
			v[i] = v[i+1] + (s[i] == 'B')*pv;
			if (v[i+1]+b[i] < minCost1) minCost1 = v[i+1]+b[i];
		}



		b[n-1] = (s[n-1] == 'B') ? 0 : pb;
		for (ll i = n-2; i >= 0; --i) {
			b[i] = b[i+1] + (s[i] == 'V')*pb;
		}

		v[0] = (s[0] == 'V') ? 0 : pv;
		ll minCost2 = b[1]+v[0];

		for (ll i = 1; i < n; ++i) {
			v[i] = v[i-1] + (s[i] == 'B')*pv;
			if (v[i-1]+b[i] < minCost2) minCost2 = v[i-1]+b[i];
		}


		cout << min(minCost1, minCost2) << endl;
	}
}