#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,lol,lol2;
	cin >> n >> lol;
	vector<unordered_set<int>>v;
	unordered_map<int,int>m;
	for (int i = 0; i < lol; ++i) {
		cin >> lol2;
		if (lol2 == 0) continue;
		set<int>setsToMerge;
		unordered_set<int>currentSet;
		for (int i = 0; i < lol2; ++i) {
			int prov;
			cin >> prov;
			currentSet.insert(prov);
			if (m.count(prov)) setsToMerge.insert(m[prov]);
		}
		if (setsToMerge.size() > 0) {
			int firstSet = *setsToMerge.begin();
			for (auto i : setsToMerge) {
				if (i == firstSet) continue;
				v[firstSet].insert(v[i].begin(), v[i].end());
				for (auto j : v[i]) m[j] = firstSet;
				v[i] = {};
			}
			v[firstSet].insert(currentSet.begin(), currentSet.end());
			for (auto j : currentSet) m[j] = firstSet;
		}
		else {
			v.push_back(currentSet);
			for (auto j : currentSet) m[j] = v.size()-1;
		}
	}

	bool mobe = true;
	for (int i = 1; i < n+1; ++i) {
		if (mobe) mobe = false;
		else cout << ' ';
		if (!m.count(i)) cout << 1;
		else cout << v[m[i]].size();
	}
	cout << endl;
}