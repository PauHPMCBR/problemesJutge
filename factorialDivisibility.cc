#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int last = 0;
	int ind = 0;
	bool possible = true;
	for (int i = 1; i < x; ++i) {
		int curr = 0;
		while (v[ind] == i) {
			++curr;
			++ind;
		}
		curr += last;
		if (curr % (i+1) == 0) {
			last = curr / (i+1);
		}
		else {
			possible = false;
			break;
		}
	}
	cout << (possible ? "Yes" : "No") << endl;
}