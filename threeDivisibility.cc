#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool>v(1e6+1, true);
unordered_set<ll>sols;
void getPrimes() {
	for (ll i = 2; i <= 1e6; ++i) {
		if (v[i]) {
			sols.insert(i*i);
			for (ll j = i*i; j <= 1e6; j += i) v[j] = 0;
		}
	}
}

int main(){
	int q;
	cin >> q;
	getPrimes();
	while (q--) {
		ll x;
		cin >> x;
		cout << (sols.count(x) ? "YES" : "NO") << endl;
	}
}