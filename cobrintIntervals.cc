#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	double current;
	while (cin >> n) {
		if (n == 0) cout << 0 << endl;
		else {
			vector<double>v(n);
			for (int i = 0; i < n; ++i) cin >> v[i];
			sort(v.begin(), v.end());
			current = v[0];
			int m = 1;
			for (int i = 1; i < n; ++i) {
				if (v[i] <= current+1) continue;
				else {current = v[i]; ++m;}
			}
			cout << m << endl;
		}
	}
}
