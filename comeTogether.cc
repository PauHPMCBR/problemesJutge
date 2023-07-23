#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int xa,ya,xb,yb,xc,yc;
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		int ans = 0;
		if ((xa-xb > 0 and xa-xc > 0) or (xa-xb < 0 and xa-xc < 0)) ans += max(abs(xa-xb), abs(xa-xc)) - abs(xc-xb);
		if ((ya-yb > 0 and ya-yc > 0) or (ya-yb < 0 and ya-yc < 0)) ans += max(abs(ya-yb), abs(ya-yc)) - abs(yc-yb);
		cout << ans+1 << endl;
	}
}