#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int block = 300;
vector<int>v;
vector<ll>sum;
int n,q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	v = vector<int>(n);
	sum = vector<ll>(n/block+3);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum[i/block] += v[i];
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos, val;
			cin >> pos >> val;
			--pos;
			sum[pos/block] += val - v[pos];
			v[pos] = val;
		}
		else {
			int l, r;
			cin >> l >> r;
			--l; --r;
			int lb = l/block;
			int rb = r/block;
			ll ans = 0;
			for (int i = lb; i <= rb; ++i) {
				int left = i*block;
				int right = min(left+block-1, n-1);
				if (l <= left && right <= r) ans += sum[i];
				else {
					for (int j = max(l, left); j <= min(r, right); ++j) {
						ans += v[j];
					}
				}
			}
			cout << ans << endl;
		}
	}
}