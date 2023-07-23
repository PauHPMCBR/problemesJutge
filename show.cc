#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int type3 = 0;
		vector<bool>occupied(m+1);
		int type1 = 0;
		int type2 = 0;
		int minPos = 1e8, maxPos = 0;

		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x > 0 and occupied[x]) continue;
			if (x > 0) {
				occupied[x] = true;
				++type3;
				minPos = min(minPos, x);
				maxPos = max(maxPos, x);
			}
			else if (x == -1) ++type1;
			else ++type2;
		}

		int sol = max(type3 + type2, type3 + type1);
		if (sol >= m) {
			cout << m << endl;
			continue;
		}

		int put = 0;
		int notPut = type3;
		for (int i = 1; i < m; ++i) {
			if (!occupied[i]) continue;
			--notPut;

			sol = max(sol, 1 + min(type1+put, i-1) + min(type2+notPut, m-i));

			++put;
		}

		cout << sol << endl;
	}
}