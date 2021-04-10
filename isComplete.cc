#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<unordered_set<int>>v(n);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a-1].insert(b-1);
		v[b-1].insert(a-1);
	}
	bool isComplete = true;
	for (int i = 0; i < n; ++i) {
		//cout << i << ' ' << v[i].size() << endl;
		if (v[i].size() == n-1 && !v[i].count(i)) continue;
		if (v[i].size() == n) continue;
		isComplete = false;
		break;
	}
	if (isComplete) cout << "YES" << endl;
	else cout << "NO" << endl;
}