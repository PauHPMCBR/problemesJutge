#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	while (cin >> n) {
		multiset<ll>picked;
		multiset<ll>extra;
		ll total = 0;
		for (ll i = 0; i < n; ++i) {
			ll prov;
			cin >> prov;
			extra.insert(prov);
			if (picked.size() < ((i+1)*2)/3) {
				auto it = extra.end();
				--it;
				picked.insert(*it);
				total += *it;
				extra.erase(extra.find(*it));
			}
			if (picked.size() > 0 && extra.size() > 0) {
				auto it = extra.end(); --it;
				auto it2 = picked.begin();
				ll v1 = *it;
				ll v2 = *it2;
				if (v1 > v2) {
					total += (v1-v2);
					picked.insert(v1);
					extra.insert(v2);
					picked.erase(picked.find(v2));
					extra.erase(extra.find(v1));
				}
			}
			cout << total << endl;
		}
		cout << "----------" << endl;
	}
}