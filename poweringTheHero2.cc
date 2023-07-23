#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n;
vector<int>v;
vector<bool>used;
vector<int>nextZ;
vector<pair<int,int>>bonus;

int get(int pos) {
	if (pos == -1) return -1;
	if (!used[pos]) return pos;
	return nextZ[pos] = get(nextZ[pos]);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		
		v = vector<int>(n);
		used = vector<bool>(n);
		nextZ = vector<int>(n+1);
		bonus = vector<pair<int,int>>(0);

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i]) bonus.push_back({v[i], i});
		}
		
		nextZ[n] = -1;
		int last0 = -1;
		for (int i = n-1; i >= 0; --i) {
			nextZ[i] = last0;
			if (v[i] == 0) last0 = i;
		}

		int res = 0;
		sort(bonus.begin(), bonus.end(), greater<>());
		for (auto i : bonus) {
			int x = get(nextZ[i.second]);
			if (x == -1) continue;
			used[x] = true;
			res += i.first;
		}

		cout << res << '\n';
	}
}