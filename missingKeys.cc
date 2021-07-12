#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	while (cin >> n) {
		/*ll t=1, c=1;
		vector<ll>v(n);
		for (ll i = 0; i < n; ++i) v[i] = i;

		while(next_permutation(v.begin(), v.end())) {
			ll fallats = 0;
			for (ll i = 0; i < n; ++i) {
				if (v[i] != i) ++fallats;
			}
			if (fallats < 4) ++c;
			++t;
		}
		cout << c << ' ' << t << endl;*/
		--n;
		ll c = (n + 2)*(2*n*n - n + 3)/6;
		++n;
		ll t = 1;
		for (ll i = 2; i <= n; ++i) {
			if (c%i == 0) c /= i;
			else t *= i;
		}
		ll d = __gcd(c, t);
		cout << c/d << '/' << t/d << endl;
	}
}