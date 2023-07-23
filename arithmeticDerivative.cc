#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<ll>v = {0LL, 4LL, 27LL, 3125LL, 823543LL, 285311670611LL, 302875106592253LL, 1000000000000000009LL};
	// v.push_back(0);
	// for (ll i = 2; i < 16; ++i) {
	// 	ll prov = 1;
	// 	for (ll j = 0; j < i; ++j) prov *= i;
	// 	v.push_back(prov);
	// }
	// v.push_back(1000000000000000009);
	//for (int i = 0; i < v.size(); ++i) cout << i << ' ' << v[i] << endl;
	long long l, r;
	while (cin >> l >> r) {
		int ind1 = 0, ind2 = v.size()-1;
		
		while (v[ind1] < l) ++ind1;
		while (v[ind2] > r) --ind2;
		cout << ind2 - ind1 + 1 << endl;
	}
}