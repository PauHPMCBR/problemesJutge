#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if ((n*m)%2 != 0) cout << "NO" << endl;
		else {
			if (n%2 == 0) {
				for (int i = 0; i < n; ++i){
					for (int j = 0; j < m; ++j) {
						if (i < n/2) cout << '#';
						else cout << '.';
					}
					cout << endl;
				}
			}
			else {
				for (int i = 0; i < n; ++i){
					for (int j = 0; j < m; ++j) {
						if (j < m/2) cout << '#';
						else cout << '.';
					}
					cout << endl;
				}
			}
		}
	}
}