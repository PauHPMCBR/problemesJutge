#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(ll x) {
	cout << "? " << x << endl;
	ll res; cin >> res;
	return res;
}

int main(){
	ll n;
	cin >> n;
	if (n == 2) {
	ll value = 1;
	set<ll>ans;
	for (ll i = 0; i < 31 && ans.size() < n; ++i) {
		ll res = ask(value-1);
		ll current = res^(value-1);
		ans.insert(current);

		if (current != 0) {
			ll res2 = ask(current-1);
			while (!ans.count(res2^(current-1)) && ans.size() < n) {
				current = res2^(current-1);
				ans.insert(current);
				res2 = ask(current-1);
			}
		}
		value *= 2;
	}
	cout << "!";
	for (auto i : ans) cout << ' ' << i;
	cout << endl;
	}
	else {
		set<int>ans;
		for (int i = 0; i < 20000; ++i) {
			if (ask(i) == 0) ans.insert(i);
		}
		cout << '!';
		for (auto i : ans) cout << ' ' << i;
		cout << endl;
	}
}