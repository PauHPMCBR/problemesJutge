#include <bits/stdc++.h>
using namespace std;

vector<bool>v;
void f(int n) {
	for (int i = 2; i <= n; ++i) {
		if (v[i]) {
			for (int j = i*2; j <= n; j += i) v[j] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	v = vector<bool>(n+1, true);
	f(n);
	for (int i = 5; i <= n; ++i) {
		if (v[i] and v[i-2]) cout << i-2 << ' ' << i << endl;
	}
}