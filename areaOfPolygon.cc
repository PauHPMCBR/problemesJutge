#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, area = 0;
	cin >> n;
	vector<pair<ll,ll>>v(n);
	cin >> v[0].first >> v[0].second;
	for (ll i = 1; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
		area -= v[i].first * v[i-1].second;
		area += v[i].second * v[i-1].first;
	}
	area -= v[0].first * v[n-1].second;
	area += v[0].second * v[n-1].first;
	if (area < 0) area *= -1;
	cout << area << endl;
}