#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), greater<int>());
		if (v[k] == v[k-1]) cout << "EMPATE" << endl;
		else cout << "BIEN" << endl;
	}
}