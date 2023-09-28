#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int a,s,r;
	while (cin >> a >> s >> r) {
		cout << ((s*s-2*a*s*r) >= 0 ? "yes" : "no") << endl;
	}
}