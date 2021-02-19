#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, c;
	cin >> t;
	while (t--) {
		int c1 = 0, c2 = 0, b = 0, a = 0;
		cin >> n >> c;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (i == 1) {
				if (v[1]==0) ++a;
				else ++c1;
			}
			else if (i != 0) {
				if (v[i-2]==0) {
					if (v[i]==0)
				}
			}

		}
	}
}