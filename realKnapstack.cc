#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, w;
	cin >> n >> w;
	double stonks = 0;
	for (ll i = 0; i < n; ++i) {
		double a,b;
		cin >> a >> b;
		if (a/b > stonks) stonks = a/b;
	}
	cout << setprecision(10) << fixed << stonks*w << endl;
}