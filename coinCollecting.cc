#include <bits/stdc++.h>
using namespace std;

int r;
vector<vector<int>>v;
vector<int>pSize;
vector<int>parent;

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (pSize[a] < pSize[b]) swap(a, b);
        parent[b] = a;
        pSize[a] += pSize[b];
    }
}

int b(int pos) {
	if (pos == r) return 0;
	int sol = b(pos+1);

	if (parent[v[pos][0]] != parent[v[pos][1]]) {
		int oldA = parent[v[pos][0]];
		int oldB = parent[v[pos][1]];
		union_sets(v[pos][0], v[pos][1]);
		sol = max(sol, b(pos+1)+1);
		parent[v[pos][0]] = oldA;
		parent[v[pos][1]] = oldB;
	}

	if (parent[v[pos][2]] != parent[v[pos][3]]) {
		int oldA = parent[v[pos][2]];
		int oldB = parent[v[pos][3]];
		union_sets(v[pos][2], v[pos][3]);
		sol = max(sol, b(pos+1)+1);
		parent[v[pos][2]] = oldA;
		parent[v[pos][3]] = oldB;
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> r) {
		if (r == 0) break;
		v = vector<vector<int>>(r, vector<int>(4));
		pSize = vector<int>(10001, 1);
		parent = vector<int>(10001);
		for (int i = 0; i < 10001; ++i) parent[i] = i;

		for (int i = 0; i < r; ++i) {
			cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
		}
		cout << b(0)*2 << '\n';
	}
}