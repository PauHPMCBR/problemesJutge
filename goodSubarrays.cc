#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll>v(n);
		ll ans = 0;
		ll startPos = 0;
		for (ll i = 0; i < n; ++i) {
			cin >> v[i];
			if (i-v[i]+1 > startPos) {
				ans += ((i-v[i]+1-startPos)*(i-v[i]-startPos))/2 + (i-v[i]+1-startPos);
				ans += (i-v[i]+1-startPos)*(v[i]-1);
				startPos = i-v[i]+1;
				//cout << i << ' ' << ans << ' ' << startPos << endl;
			}
		}
		//cout << ":" << ans << endl;
		ans += ((n-startPos)*(n-startPos)+n-startPos)/2;
		cout << ans << '\n';
	}
}	