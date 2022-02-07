#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, a, b, c, m;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> m;
		if (a < 1) a = 1;
		if (b < 1) b = 1;
		if (c < 1) c = 1;
		cout << ((a+b+c-3 >= m) ? "YES" : "NO") << endl;
	}
}