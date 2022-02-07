#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>minDiv(1e6+3, 0);
	minDiv[1] = 1;
	for (int i = 2; i < 1e6+3; ++i) {
		if (!minDiv[i]) {
			minDiv[i] = i;
			for (ll j = 1LL*i*i; j < 1e6+3; j += i) {
				if (!minDiv[j]) minDiv[j] = i;
			}
		}
	}
	int q, x;
	cin >> q;
	while (q--) {
		cin >> x;
		vector<pair<int,int>>fact;
		while (minDiv[x] != x) {
			if (fact.size() && fact[fact.size()-1].first == minDiv[x]) ++fact[fact.size()-1].second;
			else fact.push_back({minDiv[x], 1});
			x /= minDiv[x];
		}
		if (fact.size() && fact[fact.size()-1].first == minDiv[x]) ++fact[fact.size()-1].second;
		else fact.push_back({minDiv[x], 1});

		cout << fact.size() << endl;
		for (auto i : fact) cout << i.first << ' ' << i.second << endl;
	}
}