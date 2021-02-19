#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n == 3) cout << m << endl;
		else if (n == 1) {
			if (m%3 == 0) cout << m/3 << endl;
			else if (m%3 == 1) cout << m/3+3 << endl;
			else cout << m/3+2 << endl;
		}
		else {
			if (m%3 == 0) cout << m/3*2 << endl;
			else cout << m/3*2+2*(m%3) << endl;
		}
	}
}