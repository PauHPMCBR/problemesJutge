#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string,pair<int,pair<int,int>>>m;
	while (n--) {
		string type, group;
		int amount;
		cin >> type >> group >> amount;
		if (group == "any") m[type].first = amount;
		else if (group == "left") {
			m[type].second.first = amount;
		}
		else {
			m[type].second.second = amount;
		}
	}
	int sol = 0;
	bool possible = false;
	for (auto i : m) {
		int l = i.second.second.first;
		int r = i.second.second.second;
		int a = i.second.first;
		if ((a > 1) or (l > 0 and (r > 0 or a > 0)) or (r > 0 and (l > 0 or a > 0))) possible = true;
		sol += max(l, r);
		if (l == 0 and r == 0) sol += 1;
	}
	if (!possible) cout << "impossible" << endl;
	else cout << sol+1 << endl;
}