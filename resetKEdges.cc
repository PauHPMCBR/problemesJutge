#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int>v;

vector<int>depth;
int maxDepth;
int changes;
void calcChanges(int pos) {
	if (pos == 0) return;
	if (depth[pos] == maxDepth) {
		depth[pos] = -1;
		++changes;
	}
	if (v[pos] != 0) depth[v[pos]] = 0;
	calcChanges(v[pos]);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		v = vector<vector<int>>(n);
		for (int i = 1; i < n; ++i) {
			int prov;
			cin >> prov;
			v[prov-1].push_back(i);
		}

		int esq = 1, dre = n-1, mid;
		while (esq <= dre) {
			mid = (esq+dre)/2;
			maxDepth = mid;
			int changes = 0;
			for (auto i : v[0]) {
				changes += calcChanges(i, 1);
			}
			//cout << mid << ' ' << changes << endl;
			if (changes <= k) dre = mid-1;
			else esq = mid+1;
		}

		for (int x = max(1, esq-20); x <= min(n-1, esq+20); ++x) {
			maxDepth = x;
			int changes = 0;
			for (auto i : v[0]) {
				changes += calcChanges(i, 1);
			}
			if (changes <= k) {
				cout << x << endl;
				break;
			}
		}
	}
}