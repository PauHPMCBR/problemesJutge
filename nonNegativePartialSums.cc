#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<int>v(2*n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			v[n+i] = v[i];
		}
		int cnt = 0;
		vector<int>w(2*n+1,0);
		for (int i = 2*n-1; i >= 0; --i) {
			w[i] = min(w[i+1]+v[i], 0);
			if (i < n and w[i] < 0) ++cnt;
		}
		cout << n-cnt << endl;
	}
}
