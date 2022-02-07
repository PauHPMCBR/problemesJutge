#include <bits/stdc++.h>
using namespace std;

int main(){
	long long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.rbegin(), v.rend());
		bool hasSol = false;
		for (int i = 0; i < n-2; ++i) {
			if (v[i] < v[i+1]+v[i+2]) {
				hasSol = true;
				cout << v[i]+v[i+1]+v[i+2] << endl;
				break;
			}
		}
		if (!hasSol) cout << "NO HAY NINGUNO" << endl;
	}
}