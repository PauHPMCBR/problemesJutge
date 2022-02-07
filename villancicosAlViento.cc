#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	while (cin >> t) {
		if (!t) return 0;
		vector<int>v(t);
		for (int i = 0; i < t; ++i) cin >> v[i];
		reverse(v.begin(), v.end());
		int res = 0;
		int maxReach = 0;
		for (int i = 0; i < t; ++i) {
			v[i] = min(v[i], t-i-1);
			res += max(v[i]+i - max(i, maxReach), 0);
			maxReach = max(v[i]+i, maxReach);
		}
		cout << res << endl;
	}
}