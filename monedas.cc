#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<ll>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < n; ++i) {
			if (k == 0) break;
			if (v[i] <= k) k-=v[i];
		}
		cout << k << endl;
	}
}