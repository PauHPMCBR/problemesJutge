#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

int main(){
	ll t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		set<ll>s;
		ll r;
		cin >> r;
		for (ll i = 1; i < n; ++i) {
			cin >> a;
			if (a < 0) a += -1;
			s.insert(a);
			r = gcd(r, a);
		}

		if (s.count(r)) cout << "SI" << endl;
		else if (r == 1) cout << "NO" << endl;
		else {
			bool gotSol = false;
			for (int i = 1; i <= r/2+1; ++i) {
				if (r%i == 0) if (s.count(i)) {
					gotSol = true;
					cout << "SI" << endl;
					break;
				}
			}
			if (!gotSol) cout << "NO" << endl;
		}
	}
}