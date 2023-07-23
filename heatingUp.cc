#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	vector<int>vv(n);

	int maxPos = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (vv[i] > vv[maxPos]]) maxPos = i;
	}
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = vv[(maxPos+i+1)%n];
	}
}