#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll>v(n);
	vector<ll>pref(n);
	vector<ll>cost(n);
	ll total = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> v[i];
		if (i) pref[i] = v[i]+pref[i-1];
		else pref[i] = v[i];
		total += pref[i];
	}
	ll minim = -1;
	ll minPos = 0;
	for (ll i = 0; i < n; ++i) {
		if (minim == -1 || minim > total - (n-i-1)*pref[i-1]) {
			minim = total - i*pref[i];
			minPos = i;
		}
		cin >> cost[i];
	}
	cout << minPos << endl;
}