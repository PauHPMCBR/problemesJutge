#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (cin >> n) {
		if (!n) return 0;
		vector<int>v(100, 0);
		int m = 0, maxm = 0;
		while (n--) {
			int prov;
			cin >> prov;
			if (v[prov]) --m;
			else ++m;
			v[prov] = !v[prov];
			if (m > maxm) maxm = m;
		}
		cout << maxm << endl;
	}
}