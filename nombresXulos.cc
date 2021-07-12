#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll divs(ll n) {
	ll x = 0;
	for (ll i = 2; i < 10; ++i) {
		if (n%i == 0) {
			++x;
			while (n%i==0) n /= i;
		}
	}
	if (n != 1) x = 4;
	return x;
}

int main(){
	ll n;
	while (cin >> n) {
		cout << ((divs(n)==3) ? "si" : "no") << endl;
	}
}