#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int res = 0;
		while (n--) {
			int prov;
			cin >> prov;
			if (prov != 1) ++res;
		}
		cout << res << endl;
	}
}