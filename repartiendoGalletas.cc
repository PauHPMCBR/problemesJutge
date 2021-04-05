#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while (t--) {
		int prov;
		cin >> n;
		long long suma = 0;
		for (int i = 0; i < n; ++i) {cin >> prov; suma += prov;}
		if (suma % n == 0) cout << suma/n << endl;
		else cout << -1 << endl;
	}
}