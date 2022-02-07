#include <bits/stdc++.h>
using namespace std;
int block = 300;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	vector<int>v(n);
	vector<int>group(n/block+3, 1e9+2);
	vector<int>lazy(n/block+3, -1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		group[i/block] = min(group[i/block], v[i]);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l; --r;
			int lb = l/block, rb = r/block;
			for (int i = lb; i <= rb; ++i) {
				int leftBorder = i*block;
				int rightBorder = min(leftBorder+block-1, n-1);
				if (l <= leftBorder && rightBorder <= r) {
					group[i] = x;
					lazy[i] = x;
				}
				else {
					if (lazy[i] != -1) {
						for (int j = leftBorder; j <= rightBorder; ++j) {
							v[j] = lazy[i];
						}
						lazy[i] = -1;
					}
					for (int j = max(l, leftBorder); j <= min(r, rightBorder); ++j) {
						v[j] = x;
					}
					group[i] = 1e9+2;
					for (int j = leftBorder; j <= rightBorder; ++j) group[i] = min(group[i], v[j]);
				}
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			--l; --r;
			int lb = l/block, rb = r/block;
			int ans = 1e9+2;
			for (int i = lb; i <= rb; ++i) {
				int leftBorder = i*block;
				int rightBorder = min(leftBorder+block-1, n-1);
				if (l <= leftBorder && rightBorder <= r) {
					ans = min(ans, group[i]);
				}
				else {
					if (lazy[i] != -1) {
						ans = min(ans, lazy[i]);
					}
					else {
						for (int j = max(l, leftBorder); j <= min(r, rightBorder); ++j) {
							ans = min(ans, v[j]);
						}
					}
				}
			}
			cout << ans << endl;
		}
	}
}