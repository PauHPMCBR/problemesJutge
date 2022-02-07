#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, t;
	while (cin >> n >> m >> t) {
		vector<int>v1(n);
		vector<int>v2(m);
		for (int i = 0; i < n; ++i) cin >> v1[i];
		for (int i = 0; i < m; ++i) cin >> v2[i];
		v1.push_back(0);
		v2.push_back(0);
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		for (int i = 1; i <= n; ++i) v1[i] += v1[i-1];
		for (int i = 1; i <= m; ++i) v2[i] += v2[i-1];

		int posN = 0, posM = 0;
		while (posN+1 <= n && v1[posN+1] <= t) ++posN;
		while (posM+1 <= m && v2[posM+1] <= t-v1[posN]) ++posM;
		int maxV = posN + posM;
		for (; posN >= 0; --posN) {
			while (posM+1 <= m && v2[posM+1] <= t-v1[posN]) ++posM;
			maxV = max(maxV, posN + posM);
		}
		cout << maxV << endl;
	}
}