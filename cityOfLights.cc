#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<bool>v(n+1, 1);
	int on = n;
	int maxOff = 0;
	while (k--) {
		int i;
		cin >> i;
		for (int j = i; j <= n; j += i) {
			if (v[j]) --on;
			else ++on;
			v[j] = !v[j];
		}
		maxOff = max(maxOff, n - on);
	}
	cout << maxOff << endl;
}