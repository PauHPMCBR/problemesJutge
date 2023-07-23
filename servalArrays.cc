#include <bits/stdc++.h>
using namespace std;
#define int long long 

int t, n, m;
vector<int>used;
vector<int>lastUsed;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		used = vector<int>(n+m+2, 0);
		lastUsed = vector<int>(n+m+2, -1);
		vector<int>sim(n);

		for (int i = 0; i < n; ++i) {
			cin >> sim[i];
			lastUsed[sim[i]] = 0;
		}


		for (int i = 1; i <= m; ++i) {
			int p, x;
			cin >> p >> x;
			if (sim[p-1] == x) continue;
			int y = sim[p-1];
			sim[p-1] = x;
			used[y] += i - lastUsed[y];
			lastUsed[x] = i;
			lastUsed[y] = -1;
		}

		int sol = 0;
		for (int i = 0; i < n+m+2; ++i) {
			if (lastUsed[i] != -1) used[i] += m+1 - lastUsed[i];
			//cout << ':' << i << ' ' << used[i] << endl;
			sol += used[i] * (m+1 - used[i]);
		}
		sol += (n*m*(m+1));
		sol /= 2;
		cout << sol << endl;
	}
}