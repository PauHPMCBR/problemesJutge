#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector <int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		int suma = 0;
		for (int i = 0; i < n-1; ++i) suma += v[i];
		if (suma == v[n-1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}