
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q, x;
	cin >> q;
	while (q--) {
		cin >> x;
		vector<pair<int,int>>fact;
		for (int i = 2; i*i <= x; ++i) {
			int p = 0;
			while (x%i == 0) {++p; x /= i;}
			if (p != 0) fact.push_back({i, p});
		}
		if (x != 1) fact.push_back({x, 1});
		cout << fact.size() << endl;
		for (auto i : fact) cout << i.first << ' ' << i.second << endl;
	}
}