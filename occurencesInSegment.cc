#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int>st;

void add(int p, int tl, int tr, int i, int v) {
	if (tl == tr) {
		st[p] = v;
		return;
	}
	int m = (tl+tr)/2;
	if (i <= m) add(2*p, tl, m, i, v);
	else add(2*p+1, m+1, tr, i, v);
	st[p] = st[]
}

int get(int p, int tl, int tr, int l, int r, int v) {
	if (r < l) return 0;
	if (tl == l && tr == r)
}

int main() {
	cin >> n >> q;
	st = vector<int>(4*n, 0);
}