#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
vector<unordered_set<int>>anc;

void getAncestors(int pos) {
	//cout << pos << ' ' << v[pos] << endl;
	if (pos == 0) return;
	if (!anc[pos].empty()) return;
	getAncestors(v[pos]);
	anc[pos] = anc[v[pos]];
	anc[pos].insert(v[pos]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v = vector<int>(n);
	anc = vector<unordered_set<int>>(n);
	for (int i = 1; i < n; ++i) {
		cin >> v[i];
		--v[i];
	}
	for (int i = 1; i < n; ++i) {
		//cout << "debug1" << endl;
		getAncestors(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int a,b;
		cin >> a >> b;
		--a; --b;
		if (anc[a].count(b)) cout << 2 << endl;
		else if (anc[b].count(a)) cout << 1 << endl;
		else cout << 3 << endl;
	}
}