#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t, n, prov;
	cin >> t;
	while (t--) {
		cin >> n;
		int impar = 0;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> prov;
			sum += prov;
			if (prov % 2 == 1) ++impar;
		}
		if (impar == 0) {
			cout << 1 << endl;
		}
		else {
			bool gotSol = false;
			ll alternative = -1;
			vector<ll>div;
			for (ll i = 1; i*i <= sum; ++i) {
				if (sum % i == 0) {
					div.push_back(i);
					div.push_back(sum/i);
				}
			}
			sort(div.begin(), div.end());
			for (auto i : div) {
				if (i >= impar) {
					if ((sum/i)%2 == 1) {
						gotSol = true;
						cout << i << endl;
						break;
					}
				}
			}
			if (!gotSol) {
				//if (alternative != -1) cout << alternative << endl;
				cout << sum << endl;
			}
		}
	}
}