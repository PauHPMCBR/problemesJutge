#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int minDif = 2*1e9+3;
	for (int i = 0; i < n-1; ++i) {
		if (abs(v[i] - v[i+1]) < minDif) minDif = abs(v[i] - v[i+1]);
	}
	cout << minDif << endl;
}