#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll>v(n);
		bool pos = false, neg = false;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] < 0) neg = true;
			else if (v[i] > 0) pos = true;
		}
		if (neg && pos) cout << "NO" << endl;
		else {
			sort(v.begin(), v.end());
			int r = v[1]-v[0];
			bool possible = true;
			for (int i = 2; i < n; ++i) {
				if (v[i]-v[i-1] != r) {possible = false; break;}
			}
			if (possible) cout << "SI" << endl;
			else cout << "NO" << endl;
		}
	}
}