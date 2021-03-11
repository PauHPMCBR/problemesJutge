#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		bool pos = true;
		int sum = v[0]+v[n-1];
		for (int i = 1; i <= n/2; ++i) {
			if (v[i] + v[n-1-i] != sum) pos = false;
		}
		if (pos) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}