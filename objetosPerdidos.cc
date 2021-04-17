#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll>v(n);
	vector<ll>pref(n);
	vector<ll>cost(n);
	for (ll i = 0; i < n; ++i) {
		cin >> v[i];
		if (i) pref[i] = v[i]+pref[i-1];
		else pref[i] = v[i];
	}
	for (ll i = 0; i < n; ++i) cin >> cost[i];
	vector<ll>res(n);
	ll minim = -1;
	ll minimPos = -1;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			res[j] += cost[i] * abs(pref[i]-pref[j]);
			if (i == n-1) {
				if (res[j] < minim || minim == -1) {
					minim = res[j];
					minimPos = j;
				}
			}
		}
	}
	cout << minimPos << endl;
}