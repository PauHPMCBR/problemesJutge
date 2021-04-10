#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>>v(n);
	vector<int>w(n, 0);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a-1].push_back(b-1);
		++w[b-1];
	}
	queue<int>q;
	for (int i = 0; i < n; ++i) {
		//cout << i << ": " << w[i] << endl;
		if (w[i] == 0) {
			q.push(i);
		}
	}
	int x = 0;
	vector<int>rec;
	while (!q.empty()) {
		++x;
		int l = q.front();
		//cout << l << endl;
		q.pop();
		rec.push_back(l);
		for (auto i : v[l]) {
			if (!(--w[i])) {
				q.push(i);
			}
		}
	}
	if (x == n) {
		for (auto i : rec) cout << i+1 << ' ';
			cout << endl;
	}
	else cout << "IMPOSSIBLE" << endl;
}