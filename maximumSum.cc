#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int>v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n-k; ++i) {
			sum += v[i];
		}
		int maxSum = sum;

		int i1 = 0, i2 = n-k;
		for (; i2 < n; ++i2) {
			sum += v[i2];
			sum -= v[i1];
			sum -= v[i1+1];

			maxSum = max(sum, maxSum);

			i1 += 2;
		}
		cout << maxSum << endl;
	}
}