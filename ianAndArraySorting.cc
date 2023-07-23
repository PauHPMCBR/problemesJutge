#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<long long>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		if (n%2) cout << "YES" << endl;
		else {
			for (int i = 0; i < n-2; i += 2) {
				v[i+2] += v[i] - v[i+1];
				v[i+1] = v[i]; //unnecessary
			}
			if (v[n-2] > v[n-1]) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
}