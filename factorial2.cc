#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ask(ll a, ll b) {
	cout << "? " << b << ' ' << b << endl;
	string ans;
	cin >> ans;
	return (ans == "SI");
}

int main(){
	long long lel = 1;
	for (ll i = 2; i < 11; ++i) lel *= i;
	ll sol = 1;
	for (ll i = 10; i > 1; --i) {
		if (ask(0, lel)) {
			sol = i;
			break;
		}
		lel /= i;
	}
	cout << "! " << sol << endl;
}