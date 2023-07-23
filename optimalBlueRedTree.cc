#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;

int minRn, minRy, minBn, minBy;
void dfs(int x, int parent) {
	int sumR = 2, sumB = 1;
	vector<int>rn, ry, bn, by;
	for (int i : v[x]) {
		if (i == parent) continue;
		dfs(i, x);
		rn.push_back(minRn);
		ry.push_back(minRy);
		bn.push_back(minBn);
		by.push_back(minBy);
		sumR += minBy; //?
		sumB += minRy;
	}
	minRn = sumR;
	minRy = sumR;
	minBn = sumB;
	minBy = sumB;
	for (int i = 0; i < rn.size(); ++i) {
		minRy = min(minRy, sumR - by[i] + rn[i]);
		minBy = min(minBy, sumB - ry[i] + bn[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		v = vector<vector<int>>(n);
		for (int i = 0; i < n-1; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0, -1);
		cout << min(min(minRn, minRy), min(minBn, minBy)) << endl;
	}
}