#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>v;
vector<pair<int,int>>steps;

int changes;
void op(int a, int b) {
	//cout << a << ' ' << b << ' ' << v[a] << ' ' << v[b] << endl;
	steps.push_back({a,b});
	if ((v[a]/v[b]) * v[b] == v[a]) {
		if (v[a]/v[b] != v[a]) ++changes;
		v[a] = v[a]/v[b];
	}
	else {
		if (v[a]/v[b] +1 != v[a]) ++changes;
		v[a] = v[a]/v[b] +1;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		bool hasOne = false;
		bool allSame = true;
		v = vector<int>(n);
		cin >> v[0];
		if (v[0] == 1) hasOne = true;
		for (int i = 1; i < n; ++i) {
			cin >> v[i];
			if (v[i] == 1) hasOne = true;
			if (v[i] != v[0]) allSame = false;
		}

		if (allSame) cout << 0 << endl;
		else if (hasOne) cout << -1 << endl;
		else {
			steps = vector<pair<int,int>>(0);
			bool done = false;
			int ind = 1;
			changes = 0;
			while (v[0] != 2) {
				if (v[0] > v[ind]) op(0, ind);
				else if (v[0] < v[ind]) op(ind, 0);
				else {
					++ind;
					if (ind == n) {
						if (changes == 0) {done = true; break;}
						else {changes = 0; ind = 1;}
					}
				}
			}
			if (!done) {
				for (int i = 1; i < n; ++i) {
					while (v[i] != v[0]) op(i, 0);
				}
			}
			cout << steps.size() << endl;
			for (auto i : steps) cout << i.first+1 << ' ' << i.second+1 << endl;
		}
	}
}