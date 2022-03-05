#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll c, n;
	while (cin >> c >> n) {
		vector<ll>v(n);
		for (ll i = 0; i < n; ++i) {
			cin >> v[i];
		}
		set<ll>s1;
		set<ll>s2;
		s1.insert(c);
		s2.insert(c);
		ll steps = 0;
		for (ll i : v) {
			auto x = lower_bound(s1.begin(), s1.end(), i);
			auto y = lower_bound(s2.begin(), s2.end(), c-i+1);
			//cout << i << ' ' << *x << ' ' << *y << endl;
			steps += min(abs(*x-i),abs(*y-c+i-1))+1;
			s1.insert(i);
			s2.insert(c-i+1);
		}
		cout << steps << endl;
	}
}
