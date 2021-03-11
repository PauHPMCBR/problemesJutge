#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<pair<ll,ll>>v(n);
		ll a, b;
		ll maxim = 0, minim = LLONG_MAX;
		for(int i = 0; i < n; ++i){
			cin >> a >> b;
			v[i] = {a, a+b-1};
			if (a+b-1 > maxim) maxim = a+b-1;
			if (a < minim) minim = a;
		}
		sort(v.begin(), v.end());
        ll esq = minim, dre = maxim, mig = minim;
        while (esq != dre) { 
            mig = (esq+dre)/2;
            ll pos = minim-1;
            ll vpos = 0;
            ll used = 0;
            while (pos <= maxim && vpos < n && used <= k) {
            	pos = max(pos, (v[vpos].first)-1);
            	pos += mig;
            	++used;
            	while (vpos < n && v[vpos].second <= pos) ++vpos;
            }
            if (used <= k && pos >= maxim && vpos >= n) dre = mig;
            else esq = mig+1;
        }
        cout << max(esq, mig) << endl;
	}
}