#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int>v(1e6+1, 1);
	vector<int>primes;
	for (int i = 2; i < 1e6+1; ++i) {
		if (v[i] == 1) {
			primes.push_back(i);
			v[i] = i;
		}
		for (int j = 0; j < primes.size() && i*primes[j] < 1e6+1; ++j) {
			v[i*primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}

	int q, x;
	cin >> q;
	while (q--) {
		vector<pair<int,int>>sol;
		cin >> x;
		while (x != 1) {
			if (sol.size() == 0 || v[x] != sol[sol.size()-1].first) sol.push_back({v[x],1});
			else ++sol[sol.size()-1].second;
			x /= v[x];
		}
		cout << sol.size() << '\n';
		for (auto i : sol) cout << i.first << ' ' << i.second << '\n';
	}
}