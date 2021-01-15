#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 0) cout << 0;
	while(n > 0) {
		int res = n%16;
		n /= 16;
		if (res < 10) cout << res;
		else cout << char('A' + (res-10));
	}
	cout << endl;
}