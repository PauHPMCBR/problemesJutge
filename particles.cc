#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>v;
		int largest = -1e10;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov,
			largest = max(largest, prov);
			v.push_back(prov);
		}

		int sum1 = 0, sum2 = 0;
		int max1 = -1e10, max2 = -1e10;
		for (int i = 0; i < n; ++i) {
			if (v[i] < 0) continue;
			if (i%2) {
				sum1 += v[i];
				//max1 = max(max1, sum1);
				//if (sum1 < 0) sum1 = 0;
				
			}
			else {
				sum2 += v[i];
				//max2 = max(max2, sum2);
				//if (sum2 < 0) sum2 = 0;
				
			}
		}
		if (sum1 != 0) largest = max(largest, sum1);
		if (sum2 != 0) largest = max(largest, sum2);
		cout << largest << endl;
	}
}