#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t, n, m1, m2;
	cin >> t;
	while (t--) {
		cin >> n >> m1 >> m2;
		vector<ll>v1(n);
		for (ll i = 0; i < n; ++i) {
			cin >> v1[i];
		}
		ll temp;
		vector<pair<ll,bool>>v(n);
		for (ll i = 0; i < n; ++i) {
			cin >> temp;
			temp %= 2;
			v[i] = {v1[i], temp};
		}
		sort(v.begin(), v.end());
		ll esq = 0, dre = n-1;
		ll r = 0;
		while(v[esq].second && esq<dre) {++esq; ++r;}
		while(!v[dre].second && dre>esq) {--dre; ++r;}
		ll p = 0;
		for (ll i = esq; i <= dre; ++i) {
			if (v[i].second) ++p;
			else --p;
		}
		cout << abs(p)+r << endl;
	}
}